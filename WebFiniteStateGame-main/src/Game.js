import React from "react";
import Stack from "@mui/material/Stack";
import Button from "@mui/material/Button";

export default function State({ firstState, gameData }) {
  const [stateData, setStateData] = React.useState(firstState);
  const [sfLocations, setSfLocations] = React.useState(gameData.sf);

  function nextState(nextState) {
    if (nextState.length) {
      if (sfLocations.length > 0) {
        let nextLocation =
          sfLocations[Math.floor(Math.random() * sfLocations.length)];
        // give the player the option to stop helping the minions after visiting 2 locations
        sfLocations.length > 4
          ? setStateData(nextLocation)
          : setStateData((prevData) => {
              return {
                ...nextLocation,
                choices: [
                  nextLocation.choices[0],
                  {
                    text: "I'm getting tired from walking",
                    next: "dissapointedMinion",
                  },
                ],
              };
            });
        setSfLocations((prevLocations) =>
          prevLocations.filter((location) => location !== nextLocation)
        );
      } else {
        setStateData(gameData.sadMinion);
      }
    } else {
      setStateData(nextState);
    }
  }
  return (
    <>
      <h3 style={{ width: "80%" }}>{stateData.title}</h3>

      {stateData.img && (
        <img
          src={stateData.img}
          alt=""
          style={{ marginBottom: "32px", height: "60vh" }}
        ></img>
      )}

      <Stack spacing={3} direction="row">
        {stateData.choices.map((choice) => {
          return (
            <Button
              key={choice.text} // I need this so it doesn't complain
              variant="contained"
              size="large"
              // I like a little delay when clicked so you can see animation
              onClick={() =>
                setTimeout(() => {
                  nextState(gameData[choice.next]);
                }, 70)
              }
            >
              {choice.text}
            </Button>
          );
        })}
      </Stack>
    </>
  );
}
