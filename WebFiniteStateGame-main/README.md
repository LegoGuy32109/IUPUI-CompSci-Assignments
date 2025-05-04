# Josh's Finite State Game
# Please [play the game here](https://pages.github.iu.edu/joshhale/WebFiniteStateGame/) first before I spoil it, it's great ;)
# Ok you played it, here's how I did it
This is a game where the player traverses the world through choices and has a variety of endings, but you knew that already.

I wanted to make this game easily accessible and shareable, so I decided to make a website to host the game, as I understood how to hook up a website through GitHub-pages easily making a publicly shareable link, as well as having my source code avalible publicly. I won't go into how the site is hosted but [this site is helpful in setting one up yourself.](https://github.com/gitname/react-gh-pages) 

The Technology I used was React, which itself is based off the concept of state for a lot of it's design decisions as a web framework. I thought that would make it a great fit for making a state focused text game, with some lovely images and gifs thrown in. When I want to change what the user is seeing, move into the next state, I call the function to update the state that comes from React's useState() hook. I pass that function an object that will look something like this:
```JSON
{
    "title": "You are enjoying a pleasent day in San Francisco",
    "choices": [
      { "text": "Ok I enjoy San Fran (that's what cool people call San Francsico)", "next": "minion" },
      { "text": "Ew, west coast worst coast", "next": "badEnd" }
    ]
}
```
This JSON object contains a title, which will be displayed above the choices that are kept in an array. There is no limit to how many choices I can have as they're created dynamically, 1, 5, or none could be displayed. Each choice is just a simple object with text for the button a user can click, and a key indicating the next state to travel to. I have a bunch of objects like that with keys labeling them in a file labeled gameData.json. 
```HTML 
<Game firstState={gameData.initial} gameData={gameData} />
```
This Game component is passed the firstState, which is an object of whatever part in the story I want, and the JSON of the gameData imported from the file. Those can be changed to any file I wish so theoretically any object following the format of gameData.json can be played in this web app. 

## San Francisco Places
This may not be obvious on a first playthrough, but as you assist the minions in their search for bananas 🍌, the San Francisco areas you visit are randomly chosen from an array labeled "sf" in the gameData. That list is copied in the Game component, and when one is randomly chosen, it is removed from that list, and the button will take you to a new random location. This way the player won't revisit the same spaces twice, and the length of the list is a handy indicator of how many places the player has been to. 
```JS
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
```
After they visit two locations to no avail, an option can appear letting the player leave the minion search party assuming the goal impossible or not worth the trouble. Luckily, when going to that state the minions will plead with big puppy dog eyes for you to continue helping, and will then take you to a new random locatation if you indicate your resolve to assist. If you chose otherwise they become depressed and you end on a bad ending.

## The images
```HTML
{stateData.img && (
        <img
          src={stateData.img}
          alt=""
          style={{ marginBottom: "32px", height: "60vh" }}
        ></img>
 )}
```
In the Game component this line will only render this <img> element if it detects the stateData object has a key labeled "img", this way by default I don't need to label anything "img" making writing new nodes easy. The style is also controlled in the element, because for the style I was going for, I really didn't need anything to complex css wise in a seperate file, and could handle it element per element. 

## Graph Diagram
![Picture of Diagram with 25 nodes](/refImages/MinionGame.jpg)

This diagram was made in Draw.io, and represents the paths you can take in this Finite State Game. I would like to clarify the theme of this story is the beauty of San Francisco and the wonders it entails explored by the minions, as they learn the most valuble lesson of all, banana. I think you'll find the game highly humerous and enjoyable, but most of all, it's not that long. 
