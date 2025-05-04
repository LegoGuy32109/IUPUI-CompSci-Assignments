# Body Mass Index
Due: Fri Nov 20, 2020 11:00pmDue: Fri Nov 20, 2020 11:00pm
90/100
90/100 Points
Attempt
Attempt 1

Review Feedback
SUBMITTED: Nov 20, 2020 5:02pmSUBMITTED: Nov 20, 2020 5:02pm
Attempt 1 Score:
90/100

Anonymous Grading:
no
Unlimited Attempts Allowed
Available until Dec 11, 2020 11:00pmAvailable until Dec 11, 2020 11:00pm

Preparation
Online students please view materials up to GUI development

## Overview
Demonstrate your ability to create a graphic user interface in Python using HTML and CSS. Create a simple web server with Bottle. Build a web application which prompts the user for his or her height and weight, sends that data to another page, which calculates the BMI as well as some feedback.

## About BMI
Body Mass Index (BMI) is a predictor of health based on an easily calculated formula. The essential formula is this:

```[weight /  (height)^2] x 703```
where weight is measured in pounds and height is measured in inches.

 

Body mass is evaluated according to the following chart:

BMI	status
under 18.5	underweight
18.51 to 24.9	normal
25 to 29.9	overweight
30 and over	obese
## Setting up bottle
This project requires you to set up a bottle web service on pythonanywhere.  It is possible to run this project from a local machine for testing, but pythonanywhere makes it easier for us to see and grade your project. 

Navigate to pythonanywhere and login as usual
Move to the web tab
Click on the "New Web Project" button
Choose the latest versions of bottle and python
You will be given a default directory (mysite) - that's fine for now or you can change it
Go back to the files system and you'll see the mysite directory along with a prototype bottle_ap.py
Test it as-is before you make changes
You'll definitely want to add a views directory to mysite.  
You may also want a static directory. If you do this, be sure to also mark it as a static directory in the web panel.
## The Form Interface
Create a web-based graphical interface to communicate with the user. The input form should have the following features:

Be an HTML page in the views directory displayed with the template() function
Text fields to input height in feet and inches
A text field to input weight
Labels to indicate BMI and the user's status (underweight, normal, and so on...)
Labels to explain what each text field or label means
A submit button to begin the calculation
A form with the appropriate method and action
## Result calculator
Modify your server so that it maps results to a second page.  This page should have the following:

Be an HTML template stored in the views directory loaded by the template function
Have a python section (use the <%  %> tricks to move to python)
Include the bottle request library
Extract all the appropriate fields from the previous forms
Write python code to produce a BMI value and description
Store these values in python variables
Create HTML for output
Incorporate python variables with the {{ }} operators
## Tips
Diagram your UIs first on paper
Focus on functionality before beauty.  Make it work before you make it pretty
Design your form for input and test it before worrying about output
Create a second page to process the data
On your first pass, you may just want to ensure that you are getting all the expected data from the form.
Errors WILL NOT BE REPORTED on the web page. If you get a server configuration error, use the web panel of pythonanywhere to look at the error log.  You may need to refresh the error log to see the last error message.
Combine the feet and inches fields to determine total height
You may need to convert variable types for input and output
Calculate the user's BMI status according to the chart above, and report this to the user
Even if you know how to do all this on the client-side with JavaScript, that's NOT the point of this app.  The goal here is to apply your server-side python knowledge.
## Submission
Please submit the following on Canvas:

A link to your working, finished project on pythonanywhere. For example, I may submit a link like
bltroutm.pythonanywhere.com/bmi
In this case, I would have routed my project to /bmi, but you can route it wherever you want—just give us a working link to your application. You can post this link as a submission comment, no need to get too fancy here.
A zipped file of your web server project. Clarification and tutorial hereLinks to an external site.
A .txt file describing your algorithm (congruent with the requirements for algorithm files described in the announcement about algorithm files)
If you are turning in a blackbelt version, please make a new webpage for it and give us a link to that separate webpage (assuming all of your black belt files are already included in your original zip file). So for example, I might post a link to my base assignment with bltroutm.pythonanywhere.com/bmi, and also post a link to my blackbelt that might be bltroutm.pythonanywhere.com/bmi_blackbelt. Again, make the routes whatever you want, just give us links that work and make sure your base assignment link is different from your blackbelt link.
## BlackBelt
Add more features to this calculator, or do a similar calculation (unit converter, currency calculator.) Or use the skills you learned here to add a GUI to one of your earlier projects. (Note it's easier to completely re-write a program for a GUI than to try and hack one on after the fact.)

Or maybe you want to experiment with one of the many interface libraries you can use to improve the effect.  Note that if you need to add CSS or javaScript, it will need to go in static directories.
