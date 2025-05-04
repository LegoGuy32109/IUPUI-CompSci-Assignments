import { initializeApp } from "https://www.gstatic.com/firebasejs/9.15.0/firebase-app.js";
import {
    getDatabase,
    ref,
    push,
    get,
    set,
} from "https://www.gstatic.com/firebasejs/9.15.0/firebase-database.js";

import { Account } from "./AccountClass";
import { Message } from "./Message_Class";

const appSettings = {
    databaseURL: "https://termproject-97a66-default-rtdb.firebaseio.com/",
};

const app = initializeApp(appSettings);
const database = getDatabase(app);
const usersInDB = ref(database, "users");
const messagesInDB = ref(database, "messages");

// Takes in Account object
export function createUser(user, setCall) {
    getIdFromUser(user.username).then((i) => {
        if (i) {
            console.log("User already found! Do you mean login?");
        } else {
            push(usersInDB, user.getData());
            console.log(`new user '${user.username}' created`);
            loginUser(user.username, user.password, setCall);
        }
    });
}

// return pair {id: "-Nasd1_", {<user object>}}
export async function sendFriendRequestTo(username, myPair) {
    let userPair = null;
    await getUsers().then((users) => {
        Object.entries(users).forEach(pair => {
            if (pair[1].username === username) {
                addFriendRequestToPair(pair, myPair);
                userPair = pair;
            }
        });
    });
    return userPair;
}

async function addFriendRequestToPair(pair, myPair) {
    let myId = Object.keys(myPair)[0]
    let myName = Object.values(myPair)[0]
    set(ref(database, 'users/' + pair[0]), {
        ...pair[1],
        friendRequests: { ...pair[1].friendRequests, [myId]: myName }
    }).catch((error) => {
        console.log("writing new friendRequestError", error);
    });
}

export async function addFriend(myId, myObj, friendPair){
    // make sure user in myObj has removed friendRequest 
    console.log(myId, myObj, friendPair);
    set(ref(database, "users/" + myId), {
      ...myObj,
      friends: { ...myObj.friends, [friendPair[0]]: friendPair[1] },
      friendRequests: myObj.friendRequests,
    }).catch((error) => {
      console.log("adding new friend Error", error);
    });
}

export async function setFriendRequests(myId, myObj){
    set(ref(database, "users/" + myId), {
      ...myObj,
      friendRequests: myObj.friendRequests,
    }).catch((error) => {
      console.log("setting friend request error", error);
    });
}

export async function getUserFromId(id) {
    let user = null;
    await getUsers().then((users) => {
        user = users[id];
    });
    return new Account("d", "d", user);
}

async function getUsers() {
    let users = {};
    await get(usersInDB)
        .then((snapshot) => {
            users = snapshot.val();
        })
        .catch((error) => {
            console.error(error);
        });
    return users;
}

async function getMessages() {
    let messages = [];
    await get(messagesInDB)
        .then((snapshot) => {
            messages = snapshot.val();
        })
        .catch((error) => {
            console.error(error);
        });
    return messages;
}

// return id if user found
async function getIdFromUser(username) {
    let userId = null;
    await getUsers().then((users) => {
        const userKeys = Object.keys(users);

        userKeys.forEach((key, index) => {
            if (users[key].username === username) {
                userId = userKeys[index];
            }
        });
    });
    return userId;
}

export function loginUser(username, password, setCall) {
    getIdFromUser(username, password).then((i) => {
        if (i) {
            console.log(i, "User found! Navigating to userpage...");
            setCall(i);
        } else {
            console.log("No user found, would you like to create an account?");
            // setCall(false)
        }
    });
}

export function newUserMessage(idFrom, idTo, data, friendData, date) {
    const message = new Message(idFrom, idTo, data, friendData, date);
    push(messagesInDB, message.toObject());
}

export async function getUserMessages(idFrom, idTo) {
    let relevantMessages = [];
    await getMessages().then((messages) => {
        if (messages) {
            Object.values(messages).forEach((message) => {
                if (
                    (message.reciever === idTo && message.sender === idFrom) ||
                    (message.reciever === idFrom && message.sender === idTo)
                ) {
                    relevantMessages.push(
                        new Message(
                            message.sender,
                            message.reciever,
                            message.data,
                            message.friendData,
                            message.date
                        )
                    );
                }
            });
        }
    });
    return relevantMessages;
}
