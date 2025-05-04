/**************************************
 TITLE: Message_Class
 AUTHOR: Zachary Hayes
 CREATE DATE: 2/21/2023
 PURPOSE: To implement a message object
***************************************/

export class Message {
  constructor(sentBy, recievedBy, data, friendData, dateTime) {
    this.sender = sentBy;
    this.reciever = recievedBy;
    this.data = data;
    this.friendData = friendData
    this.date = dateTime;
  } //End Constructor

  toObject() {
    return {
      sender: this.sender,
      reciever: this.reciever,
      data: this.data,
      friendData: this.friendData,
      date: this.date,
    };
  }

  //Getter for the sender of the message
  sender() {
    return this.sender;
  }

  //Getter for the reciever of the message
  reciever() {
    return this.reciever;
  }

  //Getter for the encrypted data of the message
  data() {
    return this.data;
  }

  // getter for the encrypted friendData of the message
  friendData() {
    return this.friendData
  }

  //Getter for the date the message was sent
  date() {
    return this.date;
  }
}
