import {
  getUserFromId,
  sendFriendRequestTo,
  getUserMessages,
  newUserMessage,
  addFriend,
  setFriendRequests,
} from "../database";
import React from "react";

export default function User() {
  const userId = window.location.href.split("/user/")[1];
  const [user, setUserInfo] = React.useState({});

  // array of Message objects, they are initially encrypted
  const [friendMessages, setFriendMessages] = React.useState(null);
  const [friend, setFriend] = React.useState({ id: null, convoOpen: false });
  const [friends, setFriends] = React.useState(null);

  function encrypt(text) {
    return user.publicKey.encrypt(text);
  }

  function friendEncrypt(text) {
    return friend.account.publicKey.encrypt(text);
  }

  function decrypt(text) {
    return user.privateKey.decrypt(text);
  }

  async function refreshMessages() {
    const messages = await getUserMessages(userId, friend.id);
    setFriendMessages(messages);
  }

  React.useEffect(() => {
    async function setUserData() {
      let user = await getUserFromId(userId);
      setUserInfo(user);
      if (!friend.id) {
        if (user.friends) {
          Object.keys(user.friends).map(async (friendId) => {
            const friend = await getUserFromId(friendId);
            console.log(friend);
            if (friend) {
              setFriendMessages(await getUserMessages(userId, friend.id));
              if (friends) {
                setFriends([...friends, { id: friendId, account: friend }]);
              } else {
                setFriends([{ id: friendId, account: friend }]);
              }
              // couldn't find friend, should never run
            } else {
              console.log("I can't find this friend!");
              setFriends([]);
            }
          });
          // user has no friends :(
        } else {
          setFriends([]);
        }
      }
    }

    setUserData();
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, []);

  function ChooseFriend() {
    if (friends) {
      return (
        <div>
          {user.friendRequests && <FriendRequests />}
          <h1>Message Friends</h1>
          {friends.map((friend) => {
            return (
              <button
                key={`${friend.id}but`}
                onClick={() => {
                  setFriend({
                    id: friend.id,
                    account: friend.account,
                    convoOpen: true,
                  });
                }}
              >
                {friend.account.username}
              </button>
            );
          })}
          {friends.length === 0 && (
            <h3>You don't seem to have any friends, Add one!</h3>
          )}
          <br />
          <br />
          <input id="newFriendText" type="text"></input>
          <button
            onClick={async () => {
              const newFriendEl = document.getElementById("newFriendText");
              const userPair = await sendFriendRequestTo(newFriendEl.value, {
                [userId]: user.username,
              });
              if (userPair) {
                console.log(`Friend request sent to ${newFriendEl.value}`);
              } else {
                console.log(`Could not find user ${newFriendEl.value}`);
              }
              newFriendEl.value = "";
            }}
          >
            Add Friend
          </button>
        </div>
      );
    } else {
      return <h1>Loading Friends...</h1>;
    }
  }

  function Conversation() {
    if (!friendMessages) {
      refreshMessages();
    } else if (friendMessages.length === 0) {
      console.log("no messages found :(");
    }
    return (
      <>
        <header>
          <h1>{friend.account.username}</h1>
        </header>
        <div class="forum">
          <button onClick={() => setFriend({ id: null, convoOpen: false })}>
            Exit messaging
          </button>
          <button onClick={refreshMessages}>Refresh Messages</button>
          <div class="messagesDiv">
            {friendMessages.map((message) => {
              let whichSide = message.sender === userId ? "right" : "left";
              // we also have message.date as an attrbute to add in there
              return (
                <div key={`div${message.date}`}>
                  <p
                    style={{ textAlign: whichSide }}
                    key={`text${message.date}`}
                  >
                    {
                      // If I sent it, data was encrypted with my public key,
                      // if I didn't then message.friendData was encrypted with my public key
                      message.sender === userId
                        ? decrypt(message.data)
                        : decrypt(message.friendData)
                    }
                  </p>
                </div>
              );
            })}
          </div>
          <input class="messageInput" id="messageInput" type="text" />
          <button
            class="inputSubmit"
            onClick={() => {
              const messageEl = document.getElementById("messageInput");
              let text = `${messageEl.value}`;
              let data = encrypt(text);
              let friendData = friendEncrypt(text);
              let date = new Date().toISOString();
              newUserMessage(userId, friend.id, data, friendData, date);
              messageEl.value = "";
              refreshMessages();
            }}
          >
            Send
          </button>
        </div>
      </>
    );
  }

  function FriendRequests() {
    const [showRequests, setShowRequests] = React.useState(false);
    return (
      <>
        <button
          onClick={() => {
            setShowRequests(!showRequests);
            console.log(user.friendRequests);
          }}
        >
          Show Friend Requests
        </button>
        {showRequests && (
          <>
            <br />
            {Object.entries(user.friendRequests).map((friendPair) => {
              return (
                <div>
                  <p>{friendPair[1]}</p>
                  <button
                    onClick={async () => {
                      let tempFriendRequests = user.friendRequests;
                      delete tempFriendRequests[friendPair[0]];

                      setUserInfo({
                        ...user,
                        friendRequests: tempFriendRequests,
                      }).then(
                        await addFriend(userId, user.getData(), friendPair)
                      );
                    }}
                  >
                    Accept
                  </button>
                  <button
                    onClick={async () => {
                      let tempFriendRequests = user.friendRequests;
                      delete tempFriendRequests[friendPair[0]];

                      setUserInfo({
                        ...user,
                        friendRequests: tempFriendRequests,
                      }).then(await setFriendRequests(userId, user.getData()));
                    }}
                  >
                    Ignore
                  </button>
                </div>
              );
            })}
          </>
        )}
      </>
    );
  }

  function UserPage() {
    return (
      <>
        <h1>{user.username}</h1>
        {friend.convoOpen ? <Conversation /> : <ChooseFriend />}
      </>
    );
  }

  return <>{user.username ? <UserPage /> : <h1>Loading User...</h1>}</>;
}
