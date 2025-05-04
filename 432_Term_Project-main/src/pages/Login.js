import React from "react";
import { loginUser } from "../database";
import { Navigate } from "react-router";
export default function Login({ history }) {

    const [userId, setUserId] = React.useState(null);

    return (
        <>
        <header>
                <h1>Login Page</h1>
        </header>
        <div class="forum">
        <div class="loginDiv">
            <input id="usernameInput" />
            <label for="usernameInput">Username</label>
            <br />
            <input id="passwordInput" type="password" />
            <label for="passwordInput">Password</label>
            <br />
            <button id="login-button" onClick={async () => {
                const usernameEl = document.getElementById("usernameInput");
                const passwordEl = document.getElementById("passwordInput");

                let username = usernameEl.value;
                let password = passwordEl.value;

                loginUser(username, password, setUserId)

            }}>Login</button>
            {userId && <Navigate to={`/user/${userId}`}/>}
        </div>
        </div>
        </>
    );
}