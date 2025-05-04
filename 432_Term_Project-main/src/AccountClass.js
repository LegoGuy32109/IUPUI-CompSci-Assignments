/**************************************
 TITLE: Account_Class.js
 AUTHOR: Zachary Hayes
 CREATE DATE: 3/22/2023
 PURPOSE: To implement an account class
***************************************/
const forge = require('node-forge');
var rsa = forge.pki.rsa;


export class Account {
    constructor(name, pass, dataObject = {}) {
        // not constructing from dataObject, use name and pass
        if (Object.keys(dataObject).length === 0) {
            //Account info
            this.username = name;
            this.password = pass;
            //Account keys
            const keypair = rsa.generateKeyPair({ bits: 2048, e: 0x10001 });
            this.publicKey = keypair.publicKey;
            this.privateKey = keypair.privateKey;
            //Internal Data
            this.friends = [];
            this.friendRequests = [];

            // constructing from dataObject, we don't need name or pass
        } else {
            //Account info
            this.username = dataObject.username;
            this.password = dataObject.password;
            //Account keys
            rsa.generateKeyPair({ bits: 2048, e: 0x10001 });
            this.publicKey = forge.pki.publicKeyFromPem(dataObject.publicPem);
            this.privateKey = forge.pki.privateKeyFromPem(dataObject.privatePem);
            //Internal Data
            this.friends = dataObject.friends;
            this.friendRequests = dataObject.friendRequests;
        }
    } //End Constructor

    getData() {
        return {
            "username": this.username,
            "password": this.password,
            "publicPem": forge.pki.publicKeyToPem(this.publicKey),
            "privatePem": forge.pki.privateKeyToPem(this.privateKey),
            "friends": this.friends,
            "friendsRequests": this.friendRequests,
        };
    }

    //     var rsa = forge.pki.rsa;
    // var keypair = rsa.generateKeyPair({bits: 2048, e: 0x10001});
    // var pub = rsa.setPublicKey(keypair.publicKey.n, keypair.publicKey.e);
    // var enc = pub.encrypt("Hello");
    // var dec = rsa.setPrivateKey(keypair.privateKey.n,keypair.privateKey.e, keypair.privateKey.d, keypair.privateKey.p,
    //     keypair.privateKey.q, keypair.privateKey.dP, keypair.privateKey.dQ, keypair.privateKey.qInv);
    // var ans = dec.decrypt(enc);
    // console.log(ans);

    setFriends(newFriends) {
        this.friends = newFriends
    }
    setFriendRequests(newFriendRequests) {
        this.friendRequests = newFriendRequests
    }
    
    getUsername() {
        return this.username;
    }

    getPassword() {
        return this.password;
    }

    getPublicKey() {
        return this.publicKey;
    }

    getPrivateKey() {
        return this.privateKey;
    }

    viewMessages() {
        //Implemented once database is working
    }

    sendMessage() {
        //Implemented once database is working
    }

    //The friendsName will be found via the user entering it on the html page
    sendRequest(friendsName) {
        //Parse the account database and make sure that it is a real account
        //Once account is found, call their requestRecieved function and pass in this account's name
    }

    //This function by an account that someone wishes to send a friend request to 
    //The sendersName will be recieved via the sender account passing it in
    requestRecieved(sendersName) {
        //This function gets called by someone looking to add this account as a friend
        this.friendRequests.push(sendersName);
    }

    //This is the function that will get called when on the html page, the user selects a friend request and wishes to accept it
    //The friendsName will be pulled from the html page via the user selecting it
    // acceptRequest(friendsName) {
    //     //This method gets called when the current account wants to accept a friend request
    //     this.friends.push(friendsName);
    //     //Parse the account database and find the friend who sent the request originally sent the request (friendsName), call their friendAdded function and pass in this accounts name

    //     //Remove the requester from the accpeters friendRequests array
    //     indexOfAccount = this.friendRequests.indexOf(FriendsName);
    //     if (indexOfAccount != -1) {
    //         this.friendRequests.splice(indexOfAccount, indexOfAccount);
    //     }
    // }

    //This is called when an account accpets a freind request by someone, this funstion gets called by that accepting frined
    //The passed in newFriendsName is the friend that accpeted the original request
    friendadded(newFriendsName) {
        this.friends.push(newFriendsName);
    }

    //This is called when the user wishes to deny a friend request sent by someone, the account that requested will be removed from the pending requests
    //name will be selected by the user via the html page
    // denyRequest(name) {
    //     indexOfAccount = this.friendRequests.indexOf(name);
    //     if (indexOfAccount != -1) {
    //         this.friendRequests.splice(indexOfAccount, indexOfAccount);
    //     }
    // }

} //End Class
