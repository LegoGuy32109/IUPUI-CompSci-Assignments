###GOALS###
I want to create a little pet simulator where a user can feed/play with pets that share similar attributes, but are different. This assignment will be created with abstract classes, and have data persistance as the pets will be saved to a file and be read from that file into the program. Users can add new pets, delete or free their pets, rename their pets, play, sleep, eat, and some custom stuff depending on the species like change color or rub belly. See my UML for a more visual description.

###INPUTS###
I will have the user type in the name for their pet, and choose which pet they want, chameleon or mole-rat. Of course they can have more than one pet, they may have several of either kind. They can input what food they want to feed their pet or what game they want to play with their pet, of course it's just a string so it could be anything.

###OUTPUT###
The user will experience the narration of what their pet is doing, and can see a list of all the pets they have in their 'playground'

###STEPS###
There will be an abstract 'attribute' class for the hunger and excitement classes to extend from. It will increment a set of values but will not go over or under, like sliding a mood meter. 
I also have a Pet abstract class that my mole-rats and chameleons will extend from, stuff like petName and the hunger and excitement instances will be defined there, but created in the custom Chameleon() and MoleRat() constructor. 
This will all be done inside of the main class, a Playground. That class contains an ArrayList of all the Pets as an abstract, but stores Chameleon and MoleRat objects. 
'pets.dat' will be the file name that the data of all the pets is saved too for data persistance, I'll have to reference my old assignment for BufferedWriters to remeber how to do that correctly. I need a try and multiple exception statements, ugh.
