I also included a horseSeed finder, so I could find which seeds give a three way tie. That's in the other file in blackbelt.


### Goals ###
I would like this program to have some RPG elements, like training your horse or at least feeding it stuff to increase it's stats. I really wanted to make this just because I found out I can embed emojis into vim using win + ;, it's a little buggy, and I have to ctrl+L to refresh screen to makes sure there won't be errors. But if I'm careful, I can store the emoji in a std::string and call it later. I don't recommend adding emojis in a string with other characters.

The way the horse emoji faces forces me to race them backwards, but that's just a laneLengh-i-1 so not too hard. I prettied up the track with _ instead of ., and I have side barriers with ================= top and bottom of the track. There's also a vertical finish line the horses will disapear behind, but a seperate function will check which horses have finished and display them there. The race will continue going until all horses have finished,  a little stat chart will show up at the end of the race to show each horses' efficeny moving up track and how many turns it took. 

There will be a money system where you can bet on your own horse, or other horses. Can only bet on one horse. If that horse wins, you get money back times a certain multiplier on how tough the competition, or race, is. That info will be given to the player. If you run out of money, you can sell your horses', um, valuble 'commodity' that becomes more and more expensive the better his stats. 

Each horse in this game has stats, an endurance stat for the percent chance they moveforward, the speed stat that is a very low chance the horse moves more than one space, highest value will give chance for 3 space movement. Exact values are subject to change after testing.

Another thing you can buy with money is different kind of foods you can feed to your horse, the minute it's bought it goes right in it's mouth and increments stats. You can also pay a fee to have your horse checked by a professional to see it's stats. 

When you have high enough stats the final challenge is unlocked, the triple crown, with the toughest horses in the game. When you beat them, the game is over and your horse lives in retirement.
