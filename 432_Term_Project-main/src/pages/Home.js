export default function Home() {
    return (
        <>
            <header>
                <h1>432 Term Project</h1>
            </header>

            <div class='forum'>
                <ul>
                    <li>
                        <a
                            class='btn'
                            id='Login_Btn'
                            href='login'
                        >
                            Login
                        </a>
                    </li>
                    <li>
                        <a class='btn' id='Create_Btn' href='create_account'>
                            Create Account
                        </a>
                    </li>
                </ul>
            </div>
        </>
    );
}
