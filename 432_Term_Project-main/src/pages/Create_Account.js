import { createUser } from "../database.js";
import { Account } from "../AccountClass.js";
import { Navigate } from "react-router";
import React from "react";
export default function CreateAccount() {
    const [userId, setUserId] = React.useState(null);
    return (
        <body>
            <header>
                <h1>Create User</h1>
            </header>

            <div class="forum">
                <div class="loginDiv">
                    <input id="username" type="text" />
                    <label for="username">Username</label>
                    <br />
                    <input id="password" type="password" />
                    <label for="password">Password</label>
                    <br />
                    <button id="buttonSubmit" onClick={() => {
                        //Get the data from the user
                        let usname = document.getElementById("username").value;
                        let pass = document.getElementById("password").value;
                        //Create the users account
                        const user = new Account(usname, pass);

                        //Call the database.js function
                        createUser(user, setUserId);
                    }}>Create Account</button>
                </div>
            </div>
            {userId && <Navigate to={`/user/${userId}`} />}
        </body>
    );
}