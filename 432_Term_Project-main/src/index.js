import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import {
  createBrowserRouter,
  RouterProvider,
} from "react-router-dom";

import Login from './pages/Login';
import Home from './pages/Home';
import App from './App';
import CreateAccount from './pages/Create_Account';
import User from './pages/User';
const router = createBrowserRouter([
  {
    path: "/",
    element: <App />,
    children: [
      {
        path: "/login",
        element: <Login />
      },
      {
        path: "/create_account",
        element: <CreateAccount />
      },
      {
        path: "/",
        element: <Home />
      }
    ]
  },
  {
    path: "user/:userId",
    element: <User/>
  }
]);

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <RouterProvider router={router} />
);
