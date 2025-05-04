import "./App.css";
import Game from "./Game";

import gameData from "./gameStory.json";

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <Game firstState={gameData.initial} gameData={gameData} />
      </header>
    </div>
  );
}

export default App;
