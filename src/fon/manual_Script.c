/* manual_Script.c
 *
 * Copyright (C) 1992-2008 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "ManPagesM.h"
#include "praat_version.h"

void manual_Script_init (ManPages me);
void manual_Script_init (ManPages me) {

MAN_BEGIN (L"Action commands", L"ppgb", 20021130)
INTRO (L"The commands in the @@Dynamic menu@ of the @@Object window@.")
NORMAL (L"These commands are only available if the right kinds of objects are selected. They are shown in a scrollable list, "
	"or in the #Write menu if they start with \"Write to \" or \"Append to \".")
MAN_END

MAN_BEGIN (L"Add action command...", L"ppgb", 20060920)
INTRO (L"One of the hidden commands in the Praat menu of the @@Object window@. "
	"With this command, you add a button to the dynamic menu in the Object window.")
ENTRY (L"Arguments")
NORMAL (L"See @@Add to dynamic menu...@.")
ENTRY (L"Usage")
NORMAL (L"You can use this command in your @@initialization script@ or in @@plug-ins@.")
NORMAL (L"Normally, however, if you want to add a command to the dynamic menu, "
	"you would use the command @@Add to dynamic menu...@ of the @ScriptEditor instead.")
MAN_END

MAN_BEGIN (L"Add menu command...", L"ppgb", 20060920)
INTRO (L"One of the hidden commands in the Praat menu of the @@Object window@. "
	"With this command, you add a button to any of the fixed menus in the Object or Picture window.")
ENTRY (L"Arguments")
NORMAL (L"See @@Add to fixed menu...@.")
ENTRY (L"Usage")
NORMAL (L"You can use this command in your @@initialization script@ or in @@plug-ins@.")
NORMAL (L"Normally, however, if you want to add a command to a fixed menu, "
	"you would use the command @@Add to fixed menu...@ of the @ScriptEditor instead.")
MAN_END

MAN_BEGIN (L"Add to dynamic menu...", L"ppgb", 20060920)
INTRO (L"A command in the File menu of the @ScriptEditor.")
NORMAL (L"With this command, you add a button to the dynamic menu in the @@Object window@. "
	"This button will only be visible if the specified combination of objects is selected. "
	"Clicking the button will invoke the specified @@Praat script@.")
ENTRY (L"Arguments")
TAG (L"%%Class 1")
DEFINITION (L"the name of the class of the object to be selected. "
	"For instance, if a button should only appear if the user selects a Sound, this would be \"Sound\".")
TAG (L"%%Number 1")
DEFINITION (L"the number of objects of %class1 that have to be selected. For most built-in commands, this number is unspecified (0); "
	"e.g., the user can choose #Draw... or ##To Spectrum# regardless of whether she selected 1, 2, 3, or more Sound objects. "
	"If the number of selected objects is different from %number1, the button will be visible but insensitive.")
TAG (L"%%Class 2")
DEFINITION (L"the name of the class of the second object to be selected, different from %class1. "
	"Normally the empty string (\"\").")
TAG (L"%%Number 2")
DEFINITION (L"the number of selected objects of %class2.")
TAG (L"%%Class 3")
DEFINITION (L"the name of the class of the third object to be selected, different from %class1 and %class2. "
	"Normally the empty string (\"\").")
TAG (L"%%Number 3")
DEFINITION (L"the number of selected objects of %class3.")
TAG (L"%%Command")
DEFINITION (L"the title of the new command button (or label, or submenu title). "
	"To get a separator line instead of a command text (only in a submenu), "
	"you specify a unique string that starts with a hyphen ('-'); the @ButtonEditor may contain some examples of this. "
	"If the command starts with \"Write to \", it will be placed in the @@Write menu@.")
TAG (L"%%After command")
DEFINITION (L"a button title in the dynamic menu or submenu where you want your new button. "
	"If you specify the empty string (\"\"), your button will be put at the bottom. "
	"You can specify a push button, a label (subheader), or a cascade button (submenu title) here.")
TAG (L"%%Depth")
DEFINITION (L"0 if you want your button in the main menu, 1 if you want it in a submenu.")
TAG (L"%%Script")
DEFINITION (L"the full path name of the script to invoke. If you saved the script you are editing, "
	"its name will already have been filled in here. "
	"If you do not specify a script, you will get a separating label or cascading menu title instead, "
	"depending on the %depth of the following command.")
ENTRY (L"Example")
NORMAL (L"If one object of class Sound is selected, you want a submenu called \"Filters\" "
	"after the #Convolve button, containing the commands \"Autocorrelation\" and \"Band filter...\", "
	"separated by a horizontal separator line:")
CODE (L"Add to dynamic menu... Sound 0 \"\" 0 \"\" 0 \"Filters -\" \"Convolve\" 0")
CODE (L"Add to dynamic menu... Sound 1 \"\" 0 \"\" 0 \"Autocorrelation\" \"Filters -\" 1 /u/praats/demo/autocorrelation.praat")
CODE (L"Add to dynamic menu... Sound 0 \"\" 0 \"\" 0 \"-- band filter --\" \"Autocorrelation\" 1")
CODE (L"Add to dynamic menu... Sound 1 \"\" 0 \"\" 0 \"Band filter...\" \"-- band filter --\" 1 /u/praats/demo/bandFilter.praat")
NORMAL (L"Note that \"Filters -\" will be a submenu title, %because it is followed by subcommands (%depth 1). "
	"Note that %number1 is 1 only for the executable buttons; for the cascade button and the separator line, "
	"this number is ignored.")
ENTRY (L"Usage convention")
NORMAL (L"Please adhere to the convention that commands that take arguments, end in three dots (...).")
ENTRY (L"Using this command in a script")
NORMAL (L"To add a dynamic button from a script (perhaps your @@initialization script@ or a @@plug-ins|plug-in@), "
	"use the hidden shell command @@Add action command...@ instead.")
MAN_END

MAN_BEGIN (L"Add to fixed menu...", L"ppgb", 20060920)
INTRO (L"A command in the File menu of the @ScriptEditor.")
NORMAL (L"With this command, you add a button to any fixed menu in the @@Object window@ or in the @@Picture window@. "
	"Clicking the added button will invoke the specified @@Praat script@.")
ENTRY (L"Arguments")
TAG (L"%Window")
DEFINITION (L"the name of the window (\"Objects\" or \"Picture\") that contains the menu that you want to change.")
TAG (L"%Menu")
DEFINITION (L"the title of the menu that you want to change. If %window is \"Objects\", you can specify "
	"the Praat, New, Read, Help, Goodies, or Preferences menu (for the Write menu, which depends on the objects selected, "
	"you would use @@Add to dynamic menu...@ instead). If %window is \"Picture\", you can specify "
	"the File, Edit, Margins, World, Select, Pen, Font, or Help menu.")
TAG (L"%Command")
DEFINITION (L"the title of the new menu button. To get a separator line instead of a command text, "
	"you specify a unique string that starts with a hyphen ('-'); the @ButtonEditor contains many examples of this.")
TAG (L"%%After command")
DEFINITION (L"a button title in the menu or submenu after which you want your new button to be inserted. "
	"If you specify the empty string (\"\"), your button will be put in the main menu.")
TAG (L"%Depth")
DEFINITION (L"0 if you want your button in the main menu, 1 if you want it in a submenu.")
TAG (L"%Script")
DEFINITION (L"the full path name of the script to invoke. If you saved the script you are editing, "
	"its name will already have been filled in here. If you do not specify a script, "
	"you will get a cascading menu title instead.")
ENTRY (L"Example 1")
NORMAL (L"In the #Matrix submenu of the @@New menu@, you want a separator line followed by the command \"Peaks\":")
CODE (L"Add to fixed menu... Objects New \"-- peaks --\" \"Create simple Matrix...\" 1")
CODE (L"Add to fixed menu... Objects New \"Peaks\" \"-- peaks --\" 1 /u/praats/demo/peaks.praat")
ENTRY (L"Example 2")
NORMAL (L"In the @@New menu@, you want a submenu called \"Demo\", with a subitem titled \"Lorenz...\":")
CODE (L"Add to fixed menu... Objects New \"Demo\" \"\" 0")
CODE (L"Add to fixed menu... Objects New \"Lorenz...\" \"Demo\" 1 /u/praats/demo/lorentz.praat")
ENTRY (L"Usage convention")
NORMAL (L"Please adhere to the convention that commands that take arguments, end in three dots (...).")
ENTRY (L"Using this command in a script")
NORMAL (L"To add a fixed button from a script (perhaps your @@initialization script@ or a @@plug-ins|plug-in@), "
	"use the hidden shell command @@Add menu command...@ instead.")
MAN_END

MAN_BEGIN (L"binomialQ", L"ppgb", 20021204)
INTRO (L"A function that can be used in @@Formulas@. The complement of the cumulative binomial distribution.")
ENTRY (L"Syntax")
TAG (L"$$binomialQ (%p, %k, %n)")
DEFINITION (L"the probability that in %n trials an event with probability %p will occur at least %k times.")
ENTRY (L"Calculator example")
NORMAL (L"A die is suspected to yield more sixes than a perfect die would do. In order to test this suspicion, "
	"you throw it 1,000 times. The result is 211 sixes.")
NORMAL (L"The probability that a perfect die yields at least 211 sixes is, according to @@Calculator...@, "
	"$$binomialQ (1/6, 211, 1000)$ = 0.000152.")
ENTRY (L"Script example")
NORMAL (L"You convert 1000 values of pitch targets in Hz to the nearest note on the piano keyboard. "
	"597 of those values turn out to be in the A, B, C, D, E, F, or G regions (the white keys), and 403 values turn out "
	"to be in the A\\# , C\\# , D\\# , F\\# , or G\\#  regions (the black keys). "
	"Do our subjects have a preference for the white keys? "
	"The following script computes the probability that in the case of no preference the subjects "
	"would target the white keys at least 597 times. This is compared with a %\\ci^2 test.")
CODE (L"a = 597")
CODE (L"b = 403")
CODE (L"p = 7/12 ; no preference")
CODE (L"echo *** Binomial test 'a', 'b', p = 'p:6' ***")
CODE (L"pbin = binomialQ (p, a, a+b)")
CODE (L"printline P (binomial) = 'pbin:6'")
CODE (L"\\#  Chi-square test with Yates correction:")
CODE (L"x2 = (a - 1/2 - p * (a+b))\\^ 2/(p*(a+b)) + (b + 1/2 - (1-p) * (a+b))\\^ 2/((1-p)*(a+b))")
CODE (L"px2 = chiSquareQ (x2, 1)")
CODE (L"printline P (chi-square) = 'px2:6'")
NORMAL (L"The result is:")
CODE (L"*** Binomial test 597, 403, p = 0.583333 ***")
CODE (L"P (binomial) = 0.199330")
CODE (L"P (chi-square) = 0.398365")
NORMAL (L"The %\\ci^2 test is two-sided (it signals a preference for the white or for the black keys), "
	"so it has twice the probability of the binomial test.")
NORMAL (L"We cannot conclude from this test that people have a preference for the white keys. "
	"Of course, we cannot conclude either that people do not have such a preference.")
MAN_END

MAN_BEGIN (L"ButtonEditor", L"ppgb", 20060920)
INTRO (L"An editor for viewing, hiding, showing, removing, and executing the commands "
	"in the fixed and dynamic menus of the P\\s{RAAT} program. To open it, choose ##Buttons...# "
	"from the #Praat menu of the @@Object window@.")
ENTRY (L"What the button editor shows")
NORMAL (L"The button editor gives a list of:")
LIST_ITEM (L"1. The five fixed buttons.")
LIST_ITEM (L"2. The built-in and added @@fixed menu commands@, lexicographically sorted by window and menu name.")
LIST_ITEM (L"3. The built-in and added @@action commands@, sorted by the names of the selected objects.")
ENTRY (L"Visibility of built-in commands")
NORMAL (L"Most built-in commands are visible by default, but some are hidden by default (see @@Hidden commands@). "
	"The button editor shows these commands as \"shown\" or \"hidden\", respectively. "
	"You can change the visibility of a command by clicking on the blue \"shown\" or \"hidden\" text; "
	"this text will then be replaced with \"HIDDEN\" or \"SHOWN\", with capitals to signal their non-standard settings. "
	"These changes will be remembered in the @@buttons file@ across sessions of your program. "
	"To return to the standard settings, click the blue \"HIDDEN\" or \"SHOWN\" texts again.")
NORMAL (L"Some built-in commands cannot be hidden. They are marked as \"unhidable\". "
	"The most notable example is the ##Buttons...# button "
	"(a failure to make the ##Commands...# command unhidable in Microsoft Word "
	"causes some computer viruses to be very hard to remove...).")
ENTRY (L"Added commands")
NORMAL (L"Commands that you have added to the fixed or dynamic menus (probably with @@Add to fixed menu...@ or "
	"@@Add to dynamic menu...@ in the @ScriptEditor), "
	"are marked as \"ADDED\". They are remembered in the @@buttons file@. "
	"You can change the availability of these commands by clicking on the blue \"ADDED\" text, which will then "
	"be replaced with \"REMOVED\". After this, the added command will no longer be remembered in the @@buttons file@. "
	"To make the command available again, click the blue \"REMOVED\" text again, before leaving the program.")
ENTRY (L"Start-up commands")
NORMAL (L"Commands that were added in an @@initialization script@ or @@plug-ins|plug-in@ (with @@Add menu command...@ or "
	"@@Add action command...@) are marked as \"START-UP\". "
	"They are %not remembered in the @@buttons file@. "
	"You can change the visibility of these commands by clicking on the blue \"START-UP\" text, which will then "
	"be replaced with \"HIDDEN\". This setting %will be remembered in the @@buttons file@. "
	"To make the command visible again, click the blue \"HIDDEN\" text again.")
ENTRY (L"Executing commands")
NORMAL (L"The button editor allows you to choose hidden commands without first making them visible in the fixed or dynamic menus.")
NORMAL (L"The editor shows all the executable commands in blue. These include:")
LIST_ITEM (L"1. The fixed #Remove button, if one or more objects are selected in the @@List of Objects@.")
LIST_ITEM (L"2. The other fixed buttons, if exactly one object is selected.")
LIST_ITEM (L"3. All of the fixed menu commands, hidden or not, and \"removed\" or not.")
LIST_ITEM (L"4. Those action commands that match the currently selected objects with respect to class and number.")
NORMAL (L"To execute any of these blue commands, just click on it.")
MAN_END

MAN_BEGIN (L"buttons file", L"ppgb", 20071204)
NORMAL (L"The file into which changes in the availability and visibility of commands in the fixed "
	"and dynamic menus are recorded.")
NORMAL (L"The buttons file is written to disk when you quit Praat, "
	"and it is read again when you start Praat the next time. It is a simple @@Praat script@ that you can read "
	"(but should not edit) with any text editor.")
ENTRY (L"Adding buttons")
NORMAL (L"To add a command to a fixed or dynamic menu, you typically use the @ScriptEditor.")
ENTRY (L"Removing buttons")
NORMAL (L"To remove an added command from a fixed or dynamic menu, you typically use the @ButtonEditor.")
ENTRY (L"Hiding and showing buttons")
NORMAL (L"To hide a built-in command from a fixed or dynamic menu, or to make a hidden command visible, "
	"you typically use the @ButtonEditor.")
ENTRY (L"Where is the buttons file?")
NORMAL (L"The buttons file is in your Praat @@preferences directory@.")
NORMAL (L"On Unix the file is called #buttons5, "
	"for instance ##/people/miep/.praat-dir/buttons5#.")
NORMAL (L"On Macintosh it is called #Buttons5, "
	"for instance ##/Users/miep/Library/Preferences/Praat Prefs/Buttons5#.")
NORMAL (L"On Windows it is called ##Buttons5.ini#, "
	"for instance ##C:\\bsDocuments and Settings\\bsMiep\\bsPraat\\bsButtons5.ini#.")
MAN_END

MAN_BEGIN (L"Calculator", L"ppgb", 20021201)
INTRO (L"A window that allows you to calculate all kinds of simple or complicated mathematical and string expressions. "
	"To show the calculator, type Command-U or choose the @@Calculator...@ command. "
	"The result will be written to the Info window.")
NORMAL (L"See the @Formulas tutorial for all the things that you can calculate with this command.")
MAN_END

MAN_BEGIN (L"Calculator...", L"ppgb", 20050822)
INTRO (L"A command in the @Goodies submenu of the @@Praat menu@ of the @@Object window@. Shortcut: Command-U. "
	"Choosing this command brings up Praat's @calculator.")
MAN_END

MAN_BEGIN (L"Clear history", L"ppgb", 20000927)
INTRO (L"A command in the Edit menu of the @ScriptEditor for clearing the remembered history. "
	"See @@History mechanism@.")
MAN_END

MAN_BEGIN (L"differenceLimensToPhon", L"ppgb", 20021215)
INTRO (L"A routine for converting intensity difference limens into sensation level, "
	"the inverse of @phonToDifferenceLimens.")
ENTRY (L"Formula")
FORMULA (L"differenceLimensToPhon (%ndli) = ln (1 + %ndli / 30) / ln (61 / 60)")
MAN_END

MAN_BEGIN (L"Fixed menu commands", L"ppgb", 20050822)
INTRO (L"The commands in the fixed menus of the @@Object window@ (#Praat, #New, #Read, #Help, #Goodies, "
	"and #Preferences) and the @@Picture window@ (#File, #Edit, #Margins, #World, #Select, #Pen, #Font, #Help).")
NORMAL (L"These commands are always clickable (if not hidden) and scriptable (if not added).")
MAN_END

MAN_BEGIN (L"Formulas", L"ppgb", 20040414)
INTRO (L"You can use numeric expressions and string (text) expressions in many places in Praat:")
LIST_ITEM (L"\\bu in the @calculator in Praat's @Goodies submenu;")
LIST_ITEM (L"\\bu in the numeric fields of most settings windows;")
LIST_ITEM (L"\\bu in a @@Praat script@.")
NORMAL (L"For some types of objects (mainly Sound and Matrix), you can also apply formulas to all their contents at the same time:")
LIST_ITEM (L"\\bu when you create a Sound or a Matrix from the @@New menu@;")
LIST_ITEM (L"\\bu when you choose @@Formula...@ from the @Modify menu for a selected object.")
NORMAL (L"You can read this tutorial sequentially with the help of the \"< 1\" and \"1 >\" buttons.")
LIST_ITEM (L"1. @@Formulas 1. My first formulas|My first formulas@ (where to use)")
LIST_ITEM1 (L"1.1. @@Formulas 1.1. Formulas in the calculator|Formulas in the calculator@")
LIST_ITEM1 (L"1.2. @@Formulas 1.2. Numeric expressions|Numeric expressions@")
LIST_ITEM1 (L"1.3. @@Formulas 1.3. String expressions|String expressions@")
LIST_ITEM1 (L"1.4. @@Formulas 1.4. Representation of numbers|Representation of numbers@")
LIST_ITEM1 (L"1.5. @@Formulas 1.5. Representation of strings|Representation of strings@")
LIST_ITEM1 (L"1.6. @@Formulas 1.6. Formulas in settings windows|Formulas in settings windows@")
LIST_ITEM1 (L"1.7. @@Formulas 1.7. Formulas for creation|Formulas for creation@")
LIST_ITEM1 (L"1.8. @@Formulas 1.8. Formulas for modification|Formulas for modification@")
LIST_ITEM1 (L"1.9. @@Formulas 1.9. Formulas in scripts|Formulas in scripts@")
LIST_ITEM (L"2. @@Formulas 2. Operators|Operators@ (+, -, *, /, \\^ )")
LIST_ITEM (L"3. @@Formulas 3. Constants|Constants@ (pi, e, undefined)")
LIST_ITEM (L"4. @@Formulas 4. Mathematical functions|Mathematical functions@")
LIST_ITEM (L"5. @@Formulas 5. String functions|String functions@")
LIST_ITEM (L"6. @@Formulas 6. Control structures|Control structures@ (if then else fi, semicolon)")
LIST_ITEM (L"7. @@Formulas 7. Attributes of objects|Attributes of objects@")
LIST_ITEM (L"8. @@Formulas 8. Data in objects|Data in objects@")
MAN_END

MAN_BEGIN (L"Formulas 1. My first formulas", L"ppgb", 20040414)
LIST_ITEM (L"1.1. @@Formulas 1.1. Formulas in the calculator|Formulas in the calculator@")
LIST_ITEM (L"1.2. @@Formulas 1.2. Numeric expressions|Numeric expressions@")
LIST_ITEM (L"1.3. @@Formulas 1.3. String expressions|String expressions@")
LIST_ITEM (L"1.4. @@Formulas 1.4. Representation of numbers|Representation of numbers@")
LIST_ITEM (L"1.5. @@Formulas 1.5. Representation of strings|Representation of strings@")
LIST_ITEM (L"1.6. @@Formulas 1.6. Formulas in settings windows|Formulas in settings windows@")
LIST_ITEM (L"1.7. @@Formulas 1.7. Formulas for creation|Formulas for creation@")
LIST_ITEM (L"1.8. @@Formulas 1.8. Formulas for modification|Formulas for modification@")
LIST_ITEM (L"1.9. @@Formulas 1.9. Formulas in scripts|Formulas in scripts@")
MAN_END

MAN_BEGIN (L"Formulas 1.1. Formulas in the calculator", L"ppgb", 20050822)
INTRO (L"To use the Praat @calculator, go to the @@Praat menu@ "
	"and choose @@Calculator...@ from the @Goodies submenu. Or simply type Command-U anywhere in Praat.")
ENTRY (L"Calculating numbers")
NORMAL (L"You can do arithmetic computations. Type the formula")
CODE (L"8*17")
NORMAL (L"and click OK. The Info window will pop up and show the result:")
CODE (L"136")
ENTRY (L"Calculating strings")
NORMAL (L"You can also do text computations. Type the formula")
CODE (L"\"see\" + \"king\"")
NORMAL (L"and click OK. The Info window will show the result:")
CODE (L"seeking")
MAN_END

MAN_BEGIN (L"Formulas 1.2. Numeric expressions", L"ppgb", 20050901)
INTRO (L"All the formulas whose outcome is a number are called numeric expressions. "
	"For the following examples, all the outcomes can be checked with the @calculator.")
ENTRY (L"Examples with numbers")
NORMAL (L"Some numeric expressions involve numbers only:")
TAG (L"##8*17")
DEFINITION (L"computes a multiplication. Outcome: 136.")
TAG (L"##2\\^ 10")
DEFINITION (L"computes the tenth power of 2. Outcome: 1024.")
TAG (L"##sqrt (2) / 2")
DEFINITION (L"computes the square root of 2, and divides the result by 2. Outcome: 0.7071067811865476.")
TAG (L"##sin (1/4 * pi)")
DEFINITION (L"computes the sine of %\\pi/4. Outcome: 0.7071067811865476 (again).")
ENTRY (L"Examples with strings")
NORMAL (L"Some numeric expressions compute numeric properties of strings:")
TAG (L"##length (\"internationalization\")")
DEFINITION (L"computes the length of the string \"internationalization\". Outcome: 20.")
TAG (L"##index (\"internationalization\", \"ation\")")
DEFINITION (L"computes the location of the first occurrence of the string \"ation\" in the string \"internationalization\". Outcome: 7, "
	"because the first letter of \"ation\" lines up with the seventh letter of \"internationalization\". "
	"If the substring does not occur, the outcome is 0.")
MAN_END

MAN_BEGIN (L"Formulas 1.3. String expressions", L"ppgb", 20040414)
INTRO (L"All the formulas whose outcome is a text string are called string expressions. "
	"Again, the outcomes of the following examples can be checked with the @calculator.")
TAG (L"##\"see\" + \"king\"")
DEFINITION (L"concatenates two strings. Outcome: seeking.")
TAG (L"##left\\$  (\"internationalization\", 6)")
DEFINITION (L"computes the leftmost six letters of the string; the dollar sign is used for all functions whose result is a string. Outcome: intern.")
TAG (L"##mid\\$  (\"internationalization\", 6, 8)")
DEFINITION (L"computes the 8-letter substring that starts at the sixth letter of \"internationalization\". Outcome: national.")
TAG (L"##date\\$  ( )")
DEFINITION (L"computes the current date and time. Outcome at the time I am writing this: Mon Dec  2 02:23:45 2002.")
MAN_END

MAN_BEGIN (L"Formulas 1.4. Representation of numbers", L"ppgb", 20040414)
INTRO (L"Formulas can work with integer numbers as well as with real numbers.")
ENTRY (L"Real numbers")
NORMAL (L"You can type many real numbers by using a decimal notation, for instance 3.14159, 299792.5, or -0.000123456789. "
	"For very large or small numbers, you can use the %e-notation: 6.022\\.c10^^23^ is typed as 6.022e23 or 6.022e+23, "
	"and -1.6021917\\.c10^^-19^ is typed as -1.6021917e-19. You can use also use the percent notation: 0.157 "
	"can be typed as 15.7\\% .")
NORMAL (L"There are some limitations as to the values that real numbers can have in Praat. "
	"The numbers must lie between -10^^308^ and +10^^308^. If you type")
CODE (L"1e200 * 1e100")
NORMAL (L"the outcome will be")
CODE (L"1e+300")
NORMAL (L"but if you type")
CODE (L"1e300 * 1e100")
NORMAL (L"the outcome will be")
CODE (L"--undefined--")
NORMAL (L"Another limitation is that the smallest non-zero numbers lie near -10^^-308^ and +10^^-308^. If you type")
CODE (L"1e-200 / 1e100")
NORMAL (L"the outcome will be")
CODE (L"1e-300")
NORMAL (L"but if you type")
CODE (L"1e-300 / 1e100")
NORMAL (L"the outcome will be")
CODE (L"0")
NORMAL (L"Finally, the precision of real numbers is limited by the number of bits that every real number is stored with "
	"in the computer, namely 64. For instance, if you type")
CODE (L"pi")
NORMAL (L"the outcome will be")
CODE (L"3.141592653589793")
NORMAL (L"because only 16 digits of precision are stored. This can lead to unexpected results caused by rounding. "
	"For instance, the formula")
CODE (L"0.34999999999999999 - 0.35")
NORMAL (L"will result in")
CODE (L"0")
NORMAL (L"rather than the correct value of 1e-17. This is because the numbers 0.34999999999999999 and 0.35 cannot "
	"be distinguished in the computer's memory. If you simply type")
CODE (L"0.34999999999999999")
NORMAL (L"the outcome will be")
CODE (L"0.35")
NORMAL (L"(as in this example, the calculator will always come up with the minimum number of digits needed to represent the number unambiguously).")
NORMAL (L"Another example of inaccuracy is the formula")
CODE (L"1 / 7 / 59 * 413")
NORMAL (L"Because of rounding errors, the result will be")
CODE (L"0.9999999999999999")
ENTRY (L"Integer numbers")
NORMAL (L"Formulas can work with integer (whole) numbers between -1,000,000,000,000,000 and +1,000,000,000,000,000. "
	"You type them without commas and without the plus sign: 337, -848947328345289.")
NORMAL (L"You %can work with larger numbers than that (up to 10^^308^), but there will again be rounding errors. "
	"For instance, the formula")
CODE (L"1000000000000000 + 1")
NORMAL (L"correctly yields")
CODE (L"1000000000000001")
NORMAL (L"but the formula")
CODE (L"10000000000000000 + 1")
NORMAL (L"yields an incorrect outcome:")
CODE (L"1e16")
MAN_END

MAN_BEGIN (L"Formulas 1.5. Representation of strings", L"ppgb", 20021203)
INTRO (L"Formulas can work with strings that are put between two double quotes, "
	"as in \"goodbye\" or \"how are you doing?\".")
NORMAL (L"If a string has to contain a double quote, "
	"you have to type it twice. For instance, if you type")
CODE (L"\"I asked: \\\" \\\" how are you doing?\\\" \\\" \"")
NORMAL (L"into the calculator, the outcome will be")
CODE (L"I asked: \"how are you doing?\"")
MAN_END

MAN_BEGIN (L"Formulas 1.6. Formulas in settings windows", L"ppgb", 20070225)
INTRO (L"Into numeric fields in settings windows you usually simply type a number. "
	"However, you can use any numeric expression instead.")
NORMAL (L"For instance, suppose you want to create a Sound that contains exactly 10000 samples. "
	"If the sampling frequency is 44100 Hz, the duration will be 10000/44100 seconds. "
	"You can create such a Sound by choosing @@Create Sound from formula...@ from the @@New menu@, "
	"then typing")
CODE (L"10000/44100")
NORMAL (L"into the ##%%Finishing time#% field.")
NORMAL (L"Into text fields in settings windows, you can only type text directly; there is no way "
	"to use string expressions (except if you use scripts; see @@Formulas 1.9. Formulas in scripts@).")
MAN_END

MAN_BEGIN (L"Formulas 1.7. Formulas for creation", L"ppgb", 20070225)
INTRO (L"With some commands in the @@New menu@, you can supply a formula that Praat will apply to all elements of the new object.")
ENTRY (L"Creating a Sound from a formula")
NORMAL (L"Choose @@Create Sound from formula...@ and type the following into the #%Formula field:")
CODE (L"1/2 * sin (2 * pi * 377 * x)")
NORMAL (L"When you click OK, a new @Sound object will appear in the list. "
	"After you click #%Edit and zoom in a couple of times, you will see that the sound is a sine wave "
	"with a frequency of 377 Hertz (cycles per second). This worked because the %x in the formula represents the time, "
	"i.e. the formula was applied to every sample separately, with a different value of %x for each sample.")
ENTRY (L"Creating a Matrix from a formula")
NORMAL (L"Choose @@Create simple Matrix...@ and type the following into the #%Formula field:")
CODE (L"8")
NORMAL (L"When you click OK, a new @Matrix object will appear in the list. When you click Info, "
	"you will see that it is a matrix with 10 rows and 10 columns, and that all the 100 cells contain the value 8 "
	"(you can see this because both the minimum and the maximum are reported as being 8).")
NORMAL (L"A more interesting example is the formula")
CODE (L"row * col")
NORMAL (L"For the resulting Matrix, "
	"choose @@Matrix: Paint cells...|Paint cells...@ and click OK. The Picture window will show a 10\\xx10 "
	"matrix whose elements are the product of the row and column numbers, i.e., they have values between "
	"1 and 100. Beside %row and %col, you can use %x for the distance along the horizontal axis and %y for the "
	"distance along the vertical axis; see the following page for examples.")
MAN_END

MAN_BEGIN (L"Formulas 1.8. Formulas for modification", L"ppgb", 20021204)
INTRO (L"Analogously to the formulas that you can use for creating new objects (see the previous page), "
	"you can use formulas for modifying existing objects. You do this with the command ##%Formula...%# that you "
	"can find in the @Modify menu when you select an object.")
ENTRY (L"Modifying a Sound with a formula")
NORMAL (L"Record a sound with your microphone and talk very lowly. If you don't know how to record a sound in Praat, "
	"consult the @Intro. Once the Sound objetc is in the list, click #%Play. The result will sound very soft. "
	"Then choose ##%%Formula...#% from the #%Modify menu and type")
CODE (L"self * 3")
NORMAL (L"Click OK, then click #%Play again. The sound is much louder now. You have multiplied the amplitude of every sample "
	"in the sound with a factor of 3.")
ENTRY (L"Replacing the contents of a Sound with a formula")
NORMAL (L"If you don't use $self in your formula, the formula does not refer to the existing contents of the Sound. Hence, the formula ")
CODE (L"1/2 * sin (2 * pi * 377 * x)")
NORMAL (L"will simply replace your recorded speech with a 377-Hz sine wave.")
ENTRY (L"Modifying a Matrix with a formula")
NORMAL (L"Many objects can be thought of as matrices: "
	"they consist of a number of rows and columns with data in every cell:")
LIST_ITEM (L"@Sound: one row; columns represent samples.")
LIST_ITEM (L"@Spectrum: two rows (first row is real part, second row is imaginary part); "
	"columns represent frequencies.")
LIST_ITEM (L"@Spectrogram, @Cochleagram: rows represent frequencies; columns represent times.")
LIST_ITEM (L"@Excitation: one row; columns represent frequency bands.")
LIST_ITEM (L"@Harmonicity: one row; columns represent time frames.")
NORMAL (L"The formula is performed on every column of every row. The formula")
CODE (L"self\\^ 2$")
NORMAL (L"will square all matrix elements.")
NORMAL (L"The formula first works on the first row, and in that row from the first column on; "
	"this can work recursively. The formula")
CODE (L"self + self [row, col - 1]")
NORMAL (L"integrates each row.")
ENTRY (L"Referring to the current position in the object")
NORMAL (L"You can refer to the current position in a Matrix (or Sound, etc.) by index or by %x and %y values:")
TAG (L"#row")
DEFINITION (L"the current row")
TAG (L"#col")
DEFINITION (L"the current column")
TAG (L"#x")
DEFINITION (L"the %x value associated with the current column:")
DEFINITION (L"    for a Sound, Spectrogram, Cochleagram, or Harmonicity: time")
DEFINITION (L"    for a Spectrum: frequency (Hertz)")
DEFINITION (L"    for an Excitation: frequency (Bark)")
TAG (L"#y")
DEFINITION (L"the %y value associated with the current row:")
DEFINITION (L"    for a Spectrogram: frequency (Hertz)")
DEFINITION (L"    for a Cochleagram: frequency (Bark)")
ENTRY (L"Referring to the contents of the object itself")
NORMAL (L"You can refer to values in the current Matrix (or Sound, etc.) by index.")
TAG (L"##self")
DEFINITION (L"refers to the value in the current Matrix at the current row and column, or to the value in the current Sound at the current sample.")
TAG (L"##self [%%column-expression%]")
DEFINITION (L"refers to the value in the current Sound (or Intensity etc.) at the current sample (or frame). "
	"The %%column-expression% is rounded to the nearest integer. "
	"If the index is out of range (less than 1 or greater than %n__%x_), the expression evaluates as 0.")
NORMAL (L"#Example. An integrator is")
CODE (L"   self [col - 1] + self * dx")
TAG (L"##self [%%row-expression%, %%column-expression%]")
DEFINITION (L"refers to the value in the current Matrix (or Spectrogram etc.) at the specified row and column. "
	"The expressions are rounded to the nearest integers.")
NORMAL (L"You can refer to values in the current Matrix (or Spectrogram, etc.) by %x and %y position:")
TAG (L"\\bu ##self (%%x-expression%, %%y-expression%)")
DEFINITION (L"the expressions are linearly interpolated between the four nearest matrix points.")
NORMAL (L"You can refer to values in the current Sound (or Intensity etc.) by %x position:")
TAG (L"\\bu ##self (%%x-expression%)")
DEFINITION (L"the expression is linearly interpolated between the two nearest samples (or frames).")
MAN_END

MAN_BEGIN (L"Formulas 1.9. Formulas in scripts", L"ppgb", 20070225)
INTRO (L"In scripts, you can assign numeric expressions to numeric variables, "
	"and string expressions to string variables. You can also use numeric and string variables in expressions.")
ENTRY (L"Example: report a square")
NORMAL (L"Choose @@New Praat script@ from the @@Praat menu@. A script editor window will become visible. "
	"Type the following lines into that window:")
CODE (L"x = 99")
CODE (L"x2 = x * x")
CODE (L"echo The square of 'x' is 'x2'.")
NORMAL (L"This is an example of a simple @@Praat script@; it assigns the results of the numeric formulas $$99$ and $$x * x$ "
	"to the numeric variables %x and %x2. Note that the formula $$x * x$ itself refers to the variable %x. "
	"To run (execute) this script, type Command-R or choose #%Run from the %#Run menu. "
	"Praat will then write the following text into the Info window:")
CODE (L"The square of 99 is 9801.")
NORMAL (L"For more information on scripts, see the @Scripting tutorial.")
ENTRY (L"Example: rename the city of Washington")
NORMAL (L"Type the following text into the script editor window:")
CODE (L"current\\$  = \"Bush\"")
CODE (L"previous\\$  = \"Clinton\"")
CODE (L"famous\\$  = \"Lincoln\"")
CODE (L"newCapital\\$  = current\\$  + mid\\$  (famous\\$ , 2, 3) + right\\$  (previous\\$ , 3)")
CODE (L"echo The new capital will be 'newCapital\\$ '.")
NORMAL (L"This script assigns the results of four string expressions to the four string variables %%current\\$ %, "
	"%%previous\\$ %, %%famous\\$ %, and %%newCapital\\$ %. The dollar sign is the notation for a string variable or "
	"for a function whose result is a string (like ##left\\$ #). Note that the formula in the fourth line refers to three existing "
	"variables.")
NORMAL (L"To see what the new name of the capital will be, choose #%Run.")
ENTRY (L"Example: numeric expressions in settings in scripts")
NORMAL (L"As in real settings windows, you can use numeric expressions in all numeric fields. "
	"The example of two pages back becomes:")
CODE (L"Create Sound from formula... sine Mono 0 10000/44100 44100   0.9 * sin (2*pi*377*x)")
NORMAL (L"If the numeric field is not the last field of the settings window, "
	"you will want to write the formula without any spaces, "
	"e.g. as 10000/44100, since spaces are used to separate the fields.")
ENTRY (L"Example: string expressions in settings in scripts")
NORMAL (L"As in real settings windows, you cannot use string expressions in text fields directly, "
	"but you can still use the trick of variable substitution with single quotes (see @@Scripting 5.1. Variables@):")
CODE (L"soundName\\$  = \"hello\"")
CODE (L"fileName\\$  = soundName\\$  + \".wav\"")
CODE (L"Read from file... 'fileName\\$ '")
ENTRY (L"Example: numeric expressions in creation in scripts")
NORMAL (L"Suppose you want to generate a sine wave whose frequency is held in a variable. This is the way:")
CODE (L"frequency = 377")
CODE (L"Create Sound from formula... sine Mono 0 1 44100   0.9 * sin (2*pi*frequency*x)")
NORMAL (L"In this example, Praat will protest if %x is a variable as well, because that would be ambiguous "
	"with the %x that refers to the time in the sound (see @@Formulas 1.8. Formulas for modification@).")
MAN_END

MAN_BEGIN (L"Formulas 2. Operators", L"ppgb", 20060127)
NORMAL (L"In formulas you can use the numerical and logical operators that are described on this page. "
	"The order of evaluation of the operators is the order that is most usual in programming languages. "
	"To force a different order, you use parentheses.")
NORMAL (L"The operators with the highest precedence are #negation (-) and #exponentation (\\^ ):")
CODE (L"--6 \\-> 6")
CODE (L"2\\^ 6 \\-> 64")
NORMAL (L"Sequences of negation and exponentiation are evaluated from right to left:")
CODE (L"2\\^ -6 \\-> 0.015625")
CODE (L"-(1+1)\\^ 6 \\-> -64")
CODE (L"4\\^ 3\\^ 2 \\-> 4\\^ 9 \\-> 262144")
NORMAL (L"Note that changing the spacing does not change the meaning:")
CODE (L"4\\^ 3 \\^  2 \\-> 262144")
NORMAL (L"To change the order of evaluation, you have to use parentheses:")
CODE (L"(4 \\^  3) \\^  2 \\-> 4096")
NORMAL (L"The following construction is not allowed because of an ambiguity between a negative number "
	"and negation of a positive number:")
CODE (L"-2\\^ 6 \\-> ?")
NORMAL (L"Instead, you use any of the following:")
CODE (L"(-2)\\^ 6 \\-> 64")
CODE (L"-(2\\^ 6) \\-> -64")
CODE (L"-(2)\\^ 6 \\-> -64")
NORMAL (L"The operators with the next highest precedence are #multiplication (*) and #division (/). They are evaluated "
	"from left to right:")
CODE (L"1/4*5 \\-> 1.25        (from left to right)")
CODE (L"1 / 4*5 \\-> 1.25      (spacing does not help)")
CODE (L"1 / (4*5) \\-> 0.05    (use parentheses to change the order)")
CODE (L"3 * 2 \\^  4 \\-> 48      (exponentiation before multiplication)")
CODE (L"3*2 \\^  4 \\-> 48        (this spacing does not matter and is misleading)")
CODE (L"(3 * 2) \\^  4 \\-> 1296  (use parentheses to change the order)")
NORMAL (L"##Integer division# operators (#div and #mod) have the same precedence as * and /, "
	"and are likewise evaluated from left to right:")
CODE (L"54 div 5 \\-> 10       (division rounded down)")
CODE (L"54 mod 5 \\-> 4        (the remainder)")
CODE (L"54.3 div 5.1 \\-> 10   (works for real numbers as well)")
CODE (L"54.3 mod 5.1 \\-> 3.3  (the remainder)")
CODE (L"-54 div 5 \\-> -11     (division rounded down; negation before division)")
CODE (L"-54 mod 5 \\-> 1       (the remainder)")
CODE (L"-(54 div 5) \\-> -10   (use parentheses to change the order)")
CODE (L"-(54 mod 5) \\-> -4")
CODE (L"3 * 18 div 5 \\-> 10   (from left to right)")
CODE (L"3 * (18 div 5) \\-> 9")
CODE (L"3 * 18 mod 5 \\-> 4")
CODE (L"3 * (18 mod 5) \\-> 9")
CODE (L"54 div 5 * 3 \\-> 30   (from left to right)")
CODE (L"54 div (5 * 3) \\-> 3")
CODE (L"54 mod 5 * 3 \\-> 12")
CODE (L"54 mod (5 * 3) \\-> 9")
NORMAL (L"The operators with the next highest precedence are #addition (+) and #subtraction (-), "
	"evaluated from left to right:")
CODE (L"3 - 8 + 7 \\-> 2       (from left to right)")
CODE (L"3 - (8 + 7) \\-> -12   (use parentheses to change the order)")
CODE (L"3 + 8 * 7 \\-> 59      (multiplication before addition)")
CODE (L"(3 + 8) * 7 \\-> 77    (use parentheses to change the order)")
CODE (L"3 + - (2 \\^  4) \\-> -13   (exponentiation, negation, addition)")
CODE (L"3 + 5 / 2 + 3 \\-> 8.5")
CODE (L"(3 + 5) / (2 + 3) \\-> 1.6")
NORMAL (L"The operators with the next highest precedence are the #comparison operators "
	"(=  <>  <  >  <=  >=). These operators always yield 0 (%false) or 1 (%true):")
CODE (L"5 + 6 = 10 \\-> 0      (equal)")
CODE (L"5 + 6 = 11 \\-> 1")
CODE (L"5 + 6 <> 10 \\-> 1     (unequal)")
CODE (L"5 + 6 <> 11 \\-> 0")
CODE (L"5 + 6 < 10 \\-> 0      (less than)")
CODE (L"5 + 6 < 11 \\-> 0")
CODE (L"5 + 6 > 10 \\-> 1      (greater than)")
CODE (L"5 + 6 > 11 \\-> 0")
CODE (L"5 + 6 <= 10 \\-> 0     (less than or equal)")
CODE (L"5 + 6 <= 11 \\-> 1")
CODE (L"5 + 6 >= 10 \\-> 1     (greater or equal)")
CODE (L"5 + 6 >= 11 \\-> 1")
NORMAL (L"The comparison operators are mainly used in #if, #while, and #until conditions.")
NORMAL (L"The operators of lowest precedence are the #logical operators (#not, #and, and #or), of which #not has the "
	"highest precedence and #or the lowest:")
CODE (L"not 5 + 6 = 10 \\-> 1")
CODE (L"x > 5 and x < 10               (is x between 5 and 10?)")
CODE (L"not x <= 5 and not x >= 10     (same as previous line)")
CODE (L"not (x <= 5 or x >= 10)        (same as previous line)")
ENTRY (L"String comparison")
TAG (L"##a\\$  = b\\$ ")
DEFINITION (L"gives the value %true (= 1) if the strings are equal, and %false (= 0) otherwise.")
TAG (L"##a\\$  <> b\\$ ")
DEFINITION (L"gives the value %true if the strings are unequal, and %false otherwise.")
TAG (L"##a\\$  < b\\$ ")
DEFINITION (L"gives %true if the string %%a\\$ % precedes the string %%b\\$ % in ASCII sorting order. "
	"Thus, \"ha\" < \"hal\" and \"ha\" < \"ja\" are true, but \"ha\" < \"JA\" is false, "
	"because all capitals precede all lower-case characters in the ASCII sorting order.")
TAG (L"##a\\$  > b\\$ ")
DEFINITION (L"%true if %%a\\$ % comes after %%b\\$ % in ASCII sorting order. ")
TAG (L"##a\\$  <= b\\$ ")
DEFINITION (L"gives the value %true if the string %%a\\$ % precedes the string %%b\\$ % in ASCII sorting order, "
	"or if the strings are equal.")
TAG (L"##a\\$  >= b\\$ ")
DEFINITION (L"%true if %%a\\$ % comes after %%b\\$ % or the two are equal.")
ENTRY (L"String concatenation and truncation")
TAG (L"##a\\$  + b\\$ ")
DEFINITION (L"concatenates the two strings. After")
CODE1 (L"text\\$  = \"hallo\" + \"dag\"")
DEFINITION (L"The variable %%text\\$ % contains the string \"hallodag\".")
TAG (L"##a\\$  - b\\$ ")
DEFINITION (L"subtracts the second string from the end of the first. After")
CODE2 (L"soundFileName\\$  = \"hallo.aifc\"")
CODE2 (L"textgridFileName\\$  = soundFileName\\$  - \".aifc\" + \".TextGrid\"")
DEFINITION (L"the variable %%textgridFileName\\$ % contains the string \"hallo.TextGrid\". "
	"If the first string %%a\\$ % does not end in the string %%b\\$ %, the result of the subtraction is the string %%a\\$ %.")
MAN_END

MAN_BEGIN (L"Formulas 3. Constants", L"ppgb", 20080318)
TAG (L"##pi")
DEFINITION (L"%\\pi, 3.14159265358979323846264338328")
TAG (L"##e")
DEFINITION (L"%e, 2.71828182845904523536028747135")
TAG (L"##undefined")
DEFINITION (L"a special value, see @undefined")
MAN_END

MAN_BEGIN (L"Formulas 4. Mathematical functions", L"ppgb", 20080318)
TAG (L"##abs (%x)")
DEFINITION (L"absolute value")
TAG (L"##round (%x)")
DEFINITION (L"nearest integer; round (1.5) = 2")
TAG (L"##floor (%x)")
DEFINITION (L"round down: highest integer value not greater than %x")
TAG (L"##ceiling (%x)")
DEFINITION (L"round up: lowest integer value not less than %x")
TAG (L"##sqrt (%x)")
DEFINITION (L"square root: \\Vr%x, %x \\>_ 0")
TAG (L"##min (%x, ...)")
DEFINITION (L"the minimum of a series of numbers, e.g. min (7.2, -5, 3) = -5")
TAG (L"##max (%x, ...)")
DEFINITION (L"the maximum of a series of numbers, e.g. max (7.2, -5, 3) = 7.2")
TAG (L"##imin (%x, ...)")
DEFINITION (L"the location of the minimum, e.g. imin (7.2, -5, 3) = 2")
TAG (L"##imax (%x, ...)")
DEFINITION (L"the location of the maximum, e.g. imax (7.2, -5, 3) = 1")
TAG (L"##sin (%x)")
DEFINITION (L"sine")
TAG (L"##cos (%x)")
DEFINITION (L"cosine")
TAG (L"##tan (%x)")
DEFINITION (L"tangent")
TAG (L"##arcsin (%x)")
DEFINITION (L"arcsine, -1 \\<_ %x \\<_ 1")
TAG (L"##arccos (%x)")
DEFINITION (L"arccosine, -1 \\<_ %x \\<_ 1")
TAG (L"##arctan (%x)")
DEFINITION (L"arctangent")
TAG (L"##arctan2 (%y, %x)")
DEFINITION (L"argument angle")
TAG (L"##sinc (%x)")
DEFINITION (L"sinus cardinalis: sin (%x) / %x")
TAG (L"##sincpi (%x)")
DEFINITION (L"sinc__%\\pi_: sin (%\\pi%x) / (%\\pi%x)")
TAG (L"##exp (%x)")
DEFINITION (L"exponentiation: %e^%x; same as ##e\\^ %x")
TAG (L"##ln (%x)")
DEFINITION (L"natural logarithm, base %e")
TAG (L"##log10 (%x)")
DEFINITION (L"logarithm, base 10")
TAG (L"##log2 (%x)")
DEFINITION (L"logarithm, base 2")
TAG (L"##sinh (%x)")
DEFINITION (L"hyperbolic sine: (%e^%x - %e^^-%x^) / 2")
TAG (L"##cosh (%x)")
DEFINITION (L"hyperbolic cosine: (%e^%x + %e^^-%x^) / 2")
TAG (L"##tanh (%x)")
DEFINITION (L"hyperbolic tangent: sinh (%x) / cosh (%x)")
TAG (L"##arcsinh (%x)")
DEFINITION (L"inverse hyperbolic sine: ln (%x + \\Vr(1+%x^2))")
TAG (L"##arccosh (%x)")
DEFINITION (L"inverse hyperbolic cosine: ln (%x + \\Vr(%x^2\\--1))")
TAG (L"##arctanh (%x)")
DEFINITION (L"inverse hyperbolic tangent")
TAG (L"##sigmoid (%x)")
DEFINITION (L"#R \\-> (0,1): 1 / (1 + %e^^\\--%x^) or 1 \\-- 1 / (1 + %e^%x)")
TAG (L"##invSigmoid (%x)")
DEFINITION (L"(0,1) \\-> #R: ln (%x / (1 \\-- %x))")
TAG (L"##erf (%x)")
DEFINITION (L"the error function: 2/\\Vr%\\pi __0_\\in^%x exp(-%t^2) %dt")
TAG (L"##erfc (%x)")
DEFINITION (L"the complement of the error function: 1 - erf (%x)")
TAG (L"##randomUniform (%min, %max)")
DEFINITION (L"uniform random deviate between %min (inclusive) and %max (exclusive)")
TAG (L"##randomInteger (%min, %max)")
DEFINITION (L"uniform random deviate between %min and %max (inclusive)")
TAG (L"##randomGauss (%\\mu, %\\si)")
DEFINITION (L"Gaussian random deviate with mean %\\mu and standard deviation %\\si")
TAG (L"##randomPoisson (%mean)")
DEFINITION (L"Poisson random deviate")
TAG (L"##lnGamma (%x)")
DEFINITION (L"logarithm of the \\Ga function")
TAG (L"##gaussP (%z)")
DEFINITION (L"the area under the Gaussian distribution between \\--\\oo and %z")
TAG (L"##gaussQ (%z)")
DEFINITION (L"the area under the Gaussian distribution between %z and +\\oo: "
	"the one-tailed \"statistical significance %p\" of a value that is %z standard deviations "
	"away from the mean of a Gaussian distribution")
TAG (L"##invGaussQ (%q)")
DEFINITION (L"the value of %z for which $gaussQ (%z) = %q")
TAG (L"##chiSquareP (%chiSquare, %df)")
DEFINITION (L"the area under the %\\ci^2 distribution between 0 and %chiSquare, for %df degrees of freedom")
TAG (L"##chiSquareQ (%chiSquare, %df)")
DEFINITION (L"the area under the %\\ci^2 distribution between %chiSquare and +\\oo, "
	"for %df degrees of freedom: the \"statistical significance %p\" "
	"of the %\\ci^2 difference between two distributions in %df+1 dimensions")
TAG (L"##invChiSquareQ (%q, %df)")
DEFINITION (L"the value of %\\ci^2 for which $chiSquareQ (%\\ci^2, %df) = %q")
TAG (L"##studentP (%t, %df)")
DEFINITION (L"the area under the student T-distribution from -\\oo to %t")
TAG (L"##studentQ (%t, %df)")
DEFINITION (L"the area under the student T-distribution from %t to +\\oo")
TAG (L"##invStudentQ (%q, %df)")
DEFINITION (L"the value of %t for which $studentQ (%t, %df) = %q")
TAG (L"##fisherP (%f, %df1, %df2)")
DEFINITION (L"the area under Fisher's F-distribution from 0 to %f")
TAG (L"##fisherQ (%f, %df1, %df2)")
DEFINITION (L"the area under Fisher's F-distribution from %f to +\\oo")
TAG (L"##invFisherQ (%q, %df1, %df2)")
DEFINITION (L"the value of %f for which $fisherQ (%f, %df1, %df2) = %q")
TAG (L"##binomialP (%p, %k, %n)")
DEFINITION (L"the probability that in %n experiments, an event with probability %p will occur at most %k times")
TAG (L"@binomialQ (%p, %k, %n)")
DEFINITION (L"the probability that in %n experiments, an event with probability %p will occur at least %k times; equals 1 - $binomialP (%p, %k - 1, %n)")
TAG (L"##invBinomialP (%P, %k, %n)")
DEFINITION (L"the value of %p for which $binomialP (%p, %k, %n) = %P")
TAG (L"##invBinomialQ (%Q, %k, %n)")
DEFINITION (L"the value of %p for which $binomialQ (%p, %k, %n) = %Q")
TAG (L"##hertzToBark (%x)")
DEFINITION (L"from acoustic frequency to Bark-rate (perceptual spectral frequency; place on basilar membrane): "
	"7 ln (%x/650 + \\Vr(1 + (%x/650)^2))")
TAG (L"##barkToHertz (%x)")
DEFINITION (L"650 sinh (%x / 7)")
TAG (L"##hertzToMel (%x)")
DEFINITION (L"from acoustic frequency to perceptual pitch: 550 ln (1 + %x / 550)")
TAG (L"##melToHertz (%x)")
DEFINITION (L"550 (exp (%x / 550) - 1)")
TAG (L"##hertzToSemitones (%x)")
DEFINITION (L"from acoustic frequency to a logarithmic musical scale, relative to 100 Hz: 12 ln (%x / 100) / ln 2")
TAG (L"##semitonesToHertz (%x)")
DEFINITION (L"100 exp (%x ln 2 / 12)")
TAG (L"##erb (%f)")
DEFINITION (L"the perceptual %%equivalent rectangular bandwidth% (ERB) in Hertz, for a specified acoustic frequency (also in Hertz): "
	"6.23\\.c10^^-6^ %f^2 + 0.09339 %f + 28.52")
TAG (L"##hertzToErb (%x)")
DEFINITION (L"from acoustic frequency to ERB-rate: 11.17 ln ((%x + 312) / (%x + 14680)) + 43")
TAG (L"##erbToHertz (%x)")
DEFINITION (L"(14680 %d - 312) / (1 - %d) where %d = exp ((%x - 43) / 11.17)")
TAG (L"@phonToDifferenceLimens (%x)")
DEFINITION (L"from perceptual loudness (intensity sensation) level in phon, to the number of intensity "
	"difference limens above threshold: 30 \\.c ((61/60)^^ %x^ \\-- 1).")
TAG (L"@differenceLimensToPhon (%x)")
DEFINITION (L"the inverse of the previous: ln (1 + %x / 30) / ln (61 / 60).")
TAG (L"##beta (%x, %y)")
TAG (L"##besselI (%n, %x)")
TAG (L"##besselK (%n, %x)")
MAN_END

MAN_BEGIN (L"Formulas 5. String functions", L"ppgb", 20060610)
INTRO (L"String functions are functions that either return a text string or have at least one text string as an argument. "
	"Since string computations are not very useful in the @calculator, in settings windows, or in creation and "
	"modification formulas, this page only gives examples of strings in scripts, so that the example may contain "
	"string variables.")
TAG (L"##length (a\\$ )")
DEFINITION (L"gives the length of the string. After")
CODE2 (L"string\\$  = \"hallo\"")
CODE2 (L"length = length (string\\$  + \"dag\")")
DEFINITION (L"the variable %length contains the number 8 (by the way, from this example "
	"you see that variables can have the same names as functions, without any danger of confusing the interpreter).")
TAG (L"##left\\$  (a\\$ , n)")
DEFINITION (L"gives a string consisting of the first %n characters of %%a\\$ %. After")
CODE2 (L"head\\$  = left\\$  (\"hallo\", 3)")
DEFINITION (L"the variable %%head\\$ % contains the string \"hal\".")
TAG (L"##right\\$  (a\\$ , n)")
DEFINITION (L"gives a string consisting of the last %n characters of %%a\\$ %. After")
CODE2 (L"english\\$  = \"he\" + right\\$  (\"hallo\", 3)")
DEFINITION (L"the variable %%english\\$ % contains the string \"hello\".")
TAG (L"##mid\\$  (\"hello\" , 3, 2)")
DEFINITION (L"gives a string consisting of 2 characters from \"hello\", starting at the third character. Outcome: ll.")
TAG (L"##index (a\\$ , b\\$ )")
DEFINITION (L"gives the index of the first occurrence of the string %%b\\$ % in the string %%a\\$ %. After")
CODE2 (L"where = index (\"hallo allemaal\", \"al\")")
DEFINITION (L"the variable %where contains the number 2, because the first \"al\" starts at the second character of the longer string. "
	"If the first string does not contain the second string, %index returns 0.")
TAG (L"##rindex (a\\$ , b\\$ )")
DEFINITION (L"gives the index of the last occurrence of the string %%b\\$ % in the string %%a\\$ %. After")
CODE2 (L"where = rindex (\"hallo allemaal\", \"al\")")
DEFINITION (L"the variable %where contains the number 13, because the last \"al\" starts at the 13th character. "
	"If the first string does not contain the second string, %rindex returns 0.")
TAG (L"##startsWith (a\\$ , b\\$ )")
DEFINITION (L"determines whether the string %%a\\$ % starts with the string %%b\\$ %. After")
CODE2 (L"where = startsWith (\"internationalization\", \"int\")")
DEFINITION (L"the variable %where contains the number 1 (true).")
TAG (L"##endsWith (a\\$ , b\\$ )")
DEFINITION (L"determines whether the string %%a\\$ % ends with the string %%b\\$ %. After")
CODE2 (L"where = endsWith (\"internationalization\", \"nation\")")
DEFINITION (L"the variable %where contains the number 0 (false).")
TAG (L"##replace\\$  (a\\$ , b\\$ , c\\$ , n)")
DEFINITION (L"gives a string that is like %%a\\$ %, but where (at most %n) occurrences of %%b\\$ % are replaced with the string %%c\\$ %. After")
CODE2 (L"s\\$  = replace\\$  (\"hello\", \"l\", \"m\", 0)")
DEFINITION (L"the variable %%s\\$ % contains the string \"hemmo\". After")
CODE2 (L"s\\$  = replace\\$  (\"hello\", \"l\", \"m\", 1)")
DEFINITION (L"the variable %%s\\$ % contains the string \"hemlo\". The number %n determines the maximum number of occurrences of %%b\\$ % "
	"that can be replaced. If %n is 0, all occurrences are replaced.")
TAG (L"##index_regex (a\\$ , b\\$ )")
DEFINITION (L"determines where the string %%a\\$ % first matches the @@regular expressions|regular expression@ %%b\\$ %. After")
CODE2 (L"where = index_regex (\"internationalization\", \"a.*n\")")
DEFINITION (L"the variable %where contains the number 7. If there is no match, the outcome is 0.")
TAG (L"##rindex_regex (a\\$ , b\\$ )")
DEFINITION (L"determines where the string %%a\\$ % last matches the @@regular expressions|regular expression@ %%b\\$ %. After")
CODE2 (L"where = rindex_regex (\"internationalization\", \"a.*n\")")
DEFINITION (L"the variable %where contains the number 16. If there is no match, the outcome is 0.")
TAG (L"##replace_regex\\$  (a\\$ , b\\$ , c\\$ , n)")
DEFINITION (L"gives a string that is like %%a\\$ %, but where (at most %n) substrings that match the @@regular expressions|regular expression@ %%b\\$ % "
	"are replaced with the expression %%c\\$ %. After")
CODE2 (L"s\\$  = replace_regex\\$  (\"hello\", \".\", \"&&\", 0)")
DEFINITION (L"the variable %%s\\$ % contains the string \"hheelllloo\". If there is no match, the outcome is the empty string \"\". After")
CODE2 (L"s\\$  = replace_regex\\$  (\"hello\", \".\", \"&&\", 1)")
DEFINITION (L"the variable %%s\\$ % contains the string \"hhello\". The number %n determines the maximum number of text pieces "
	"that can be replaced. If %n is 0, all matching text pieces are replaced.")
TAG (L"##fixed\\$  (number, precision)")
DEFINITION (L"formats a number as a string with %precision digits after the decimal point. Thus, $$fixed\\$  (72.65687, 3)$ "
	"becomes the string $$72.657$, and $$fixed\\$  (72.65001, 3)$ becomes the string $$72.650$. "
	"In these examples, we see that the result can be rounded up and that trailing zeroes are kept. "
	"At least one digit of precision is always given, e.g. $$fixed\\$  (0.0000157, 3)$ becomes the string $$0.00002$. "
	"The number 0 always becomes the string $0.")
TAG (L"##percent\\$  (number, precision)")
DEFINITION (L"the same as ##fixed\\$ #, but with a percent sign. For instance, $$percent\\$ (0.157, 3)$ becomes $$15.700\\% $, "
	"$$percent\\$ (0.000157, 3)$ becomes $$0.016\\% $, and $$percent\\$ (0.000000157, 3)$ becomes $$0.00002\\% $. "
	"The number 0 always becomes the string $0.")
TAG (L"##date\\$  ()")
DEFINITION (L"gives the date and time in the following format:")
CODE2 (L"Mon Jun 24 17:11:21 2002")
DEFINITION (L"To write the day of the month into the Info window, you type:")
CODE2 (L"date\\$  = date\\$  ()")
CODE2 (L"day\\$  = mid\\$  (date\\$ , 9, 2)")
CODE2 (L"echo The month day is 'day\\$ '.")
TAG (L"##extractNumber (\"Type: Sound'newline\\$ 'Name: hello there'newline\\$ 'Size: 44007\", \"Size:\")")
DEFINITION (L"looks for a number after the first occurrence of \"Size:\" in the long string. Outcome: 44007. "
	"This is useful in scripts that try to get information from long reports, as the following script that "
	"runs in the Sound editor window:")
CODE2 (L"report\\$  = Settings report")
CODE2 (L"maximumFrequency = extractNumber (report\\$ , \"Spectrogram maximum frequency:\")")
TAG (L"##extractWord\\$  (\"Type: Sound'newline\\$ 'Name: hello there'newline\\$ 'Size: 44007\", \"Type:\")")
DEFINITION (L"looks for a word without spaces after the first occurrence of \"Type:\" in the long string. Outcome: Sound.")
TAG (L"##extractLine\\$  (\"Type: Sound'newline\\$ 'Name: hello there'newline\\$ 'Size: 44007\", \"Name: \")")
DEFINITION (L"looks for the rest of the line (including spaces) after the first occurrence of \"Name: \" in the long string. "
	"Outcome: hello there. Note how \"Name: \" includes a space, so that the `rest of the line' starts with the %h.")
MAN_END

MAN_BEGIN (L"Formulas 6. Control structures", L"ppgb", 20030519)
ENTRY (L"if ... then ... else ... fi")
NORMAL (L"You can use conditional expressions in all formulas. For example, ")
CODE (L"3 * if 52\\%  * 3809 > 2000 then 5 else 6 fi")
NORMAL (L"evaluates to 15. Instead of %fi, you can also use %endif.")
NORMAL (L"Another example: you can clip the absolute amplitude of a Sound to 0.5 by supplying the following formula:")
CODE (L"if abs(self)>0.5 then if self>0 then 0.5 else -0.5 fi else self fi")
ENTRY (L"The semicolon")
NORMAL (L"The semicolon ends the evaluation of the formula. This can be convenient "
	"if you do not want to overwrite a long formula in your text field: the formula")
CODE (L"800;sqrt(2)*sin(2*pi*103*0.5)+10\\^ (-40/20)*randomGauss(0,1)")
NORMAL (L"evaluates to 800.")
MAN_END

MAN_BEGIN (L"Formulas 7. Attributes of objects", L"ppgb", 20070225)
NORMAL (L"You can refer to several attributes of objects that are visible in the @@List of Objects@. "
	"To do so, use the type and the name of the object, connected with an underscore. "
	"Thus, $$Sound_hallo$ refers to an existing Sound object whose name is \"hallo\" "
	"(if there is more than one such object, it refers to the one that was created last). "
	"You can also use the unique ID instead of the name. Thus, $$Object_113$ refers to the 113th object that you created in the list.")
NORMAL (L"To refer to an attribute, you use the period ( `.'). "
	"Thus, $$Sound_hallo.nx$ is the number of samples of Sound_hallo, and "
	"$$1 / Sound_hallo.dx$ is the sampling frequency of Sound_hallo.")
ENTRY (L"Attributes in the calculator")
NORMAL (L"Record a Sound (read the @Intro if you do not know how to do that), "
	"name it \"mysound\" (or anything else), and type the following formula into the @calculator:")
CODE (L"Sound_mysound.nx")
NORMAL (L"After you click OK, the Info window will show the number of samples. Since you could have got this result "
	"by simply choosing ##%%Get number of samples#% from the @Query menu, these attribute tricks are not very "
	"useful in the calculator. We will see that they are much more useful in creation and modification formulas and in scripts.")
ENTRY (L"List of possible attributes")
NORMAL (L"The following attributes are available:")
TAG (L"#xmin")
DEFINITION (L"the start of the time domain (usually 0) for a @Sound, @Pitch, @Formant, "
	"@Spectrogram, @Intensity, @Cochleagram, @PointProcess, or @Harmonicity object, in seconds; "
	"the lowest frequency (always 0) for a @Spectrum object, in Hertz; "
	"the lowest frequency (usually 0) for an @Excitation object, in Bark; "
	"the left edge of the %x domain for a @Matrix object.")
TAG (L"#xmax")
DEFINITION (L"the end of the time domain (usually the duration, if %xmin is zero) for a Sound, Pitch, Formant, "
	"Spectrogram, Intensity, Cochleagram, PointProcess, or Harmonicity object, in seconds; "
	"the highest frequency (@@Nyquist frequency@) for a Spectrum object, e.g. 11025 Hertz; "
	"the highest frequency for an Excitation object, often 25.6 Bark; "
	"the right edge of the %x domain for a Matrix object.")
TAG (L"#ncol")
DEFINITION (L"the number of columns in a @Matrix, @TableOfReal, or @Table object.")
TAG (L"#nrow")
DEFINITION (L"the number of rows in a @Matrix, @TableOfReal, or @Table object.")
TAG (L"##col\\$ # [%i]")
DEFINITION (L"the name of column %i in a @TableOfReal or @Table object.")
TAG (L"##row\\$ # [%i]")
DEFINITION (L"the name of row %i in a @TableOfReal object.")
TAG (L"#nx")
DEFINITION (L"the number of samples in a Sound object; "
	"the number of analysis frames in a Pitch, Formant, Spectrogram, Intensity, Cochleagram, or Harmonicity object; "
	"the number of frequency bins in a Spectrum or Excitation object; "
	"the number of divisions of the %x domain for a Matrix object (= %ncol).")
TAG (L"#dx")
DEFINITION (L"the sample period (time distance between consecutive samples) in a Sound object (the inverse of the sampling frequency), in seconds; "
	"the time step between consecutive frames in a Pitch, Formant, Spectrogram, Intensity, Cochleagram, or Harmonicity object, in seconds; "
	"the width of a frequency bin in a Spectrum object, in Hertz; "
	"the width of a frequency bin in an Excitation object, in Bark; "
	"the horizontal distance between cells in a Matrix object.")
TAG (L"#ymin")
DEFINITION (L"the lowest frequency (usually 0) for a Spectrogram object, in Hertz; "
	"the lowest frequency (usually 0) for a Cochleagram object, in Bark; "
	"the bottom of the %y domain for a Matrix object.")
TAG (L"#ymax")
DEFINITION (L"the highest frequency for a Spectrogram object, e.g. 5000 Hertz; "
	"the highest frequency for a Cochleagram object, often 25.6 Bark; "
	"the top of the %y domain for a Matrix object.")
TAG (L"#ny")
DEFINITION (L"the number of frequency bands in a Spectrogram or Cochleagram object; "
	"for a Spectrum object: always 2 (first row is real part, second row is imaginary part) "
	"the number of divisions of the %y domain for a Matrix object (= %nrow).")
TAG (L"#dy")
DEFINITION (L"the distance between adjacent frequency bands in a Spectrogram object, in Hertz; "
	"the distance between adjacent frequency bands in a Cochleagram object, in Hertz; "
	"the vertical distance between cells in a Matrix object.")
ENTRY (L"Attributes in a creation formula")
NORMAL (L"In formulas for creating a new object, you can refer to the attributes of any object, "
	"but you will often want to refer to the attributes of the object that is just being created. You can do that in two ways.")
NORMAL (L"The first way is to use the name of the object, as above. Choose @@Create Sound from formula...@, supply %hello for its name, "
	"supply arbitrary values for the starting and finishing time, and type the following formula:")
CODE (L"(x - Sound_hello.xmin) / (Sound_hello.xmax - Sound_hello.xmin)")
NORMAL (L"When you edit this sound, you can see that it creates a straight line that rises from 0 to 1 within the time domain.")
NORMAL (L"The formula above will also work if the Sound under creation is called %goodbye, and a Sound called %hello already exists; "
	"of course, in such a case $$Sound_hello.xmax$ refers to a property of the already existing sound.")
NORMAL (L"If a formula refers to an object under creation, there is a shorter way: you do not have to supply the name of the object at all, "
	"so you can simply write")
CODE (L"(x - xmin) / (xmax - xmin)")
NORMAL (L"The attributes that you can use in this implicit way are %xmin, %xmax, %ncol, %nrow, %nx, %dx, %ny, and %dy. "
	"To disambiguate in case there exists a script variable %xmin as well, you can write %%Self.xmin%.")
ENTRY (L"Attributes in a modification formula")
NORMAL (L"In formulas for modifying an existing object, you refer to attributes in the same way as in creation formulas, "
	"i.e., you do not have to specify the name of the object that is being modified. The formula")
CODE (L"self * 20 \\^  (- (x - xmin) / (xmax - xmin))")
NORMAL (L"causes the sound to decay exponentially in such a way that it has only 5 percent of its initial amplitude at the end. "
	"If you apply this formula to multiple Sound objects at the same time, %xmax will refer to the finishing time of each Sound separately "
	"as it is modified. To disambiguate in case there exists a script variable %xmin as well, you can write %%Self.xmin%.")
NORMAL (L"More examples of the use of attributes are on the next page.")
MAN_END

MAN_BEGIN (L"Formulas 8. Data in objects", L"ppgb", 20070822)
NORMAL (L"With square brackets, you can get the values inside some objects.")
ENTRY (L"Object contents in the calculator")
NORMAL (L"The outcomes of the following examples can be checked with the @calculator.")
TAG (L"##Matrix_hello [10, 3]")
DEFINITION (L"gives the value in the cell at the third column of the 10th row of the Matrix called %hello.")
TAG (L"##Sound_hello [0, 10000]")
DEFINITION (L"gives the value (in Pa) of the 1000th sample of the Sound %hello, averaged over the channels.")
TAG (L"##Sound_hello [1, 10000]")
DEFINITION (L"gives the value (in Pa) of the 1000th sample of the left channel of the Sound %hello.")
TAG (L"##Sound_hello [2, 10000]")
DEFINITION (L"gives the value (in Pa) of the 1000th sample of the right channel of the Sound %hello.")
TAG (L"##Sound_hello [10000]")
DEFINITION (L"this can mean various things. In the calculator it means the same as ##Sound_hello [0, 10000]#, "
	"but in modification formulas it can mean ##Sound_hello [row, 10000]#, where %row refers to the channel. This variation exists in order to make "
	"older Praat scripts (from the time that Praat did not support stereo) compatible with present-day Praat versions; "
	"because of possible confusions, the use of ##Sound_hello [10000]# is not recommended.")
TAG (L"##TableOfReal_tokens [5, 12]")
DEFINITION (L"gives the value in the cell at the fifth row of the 12th column of the TableOfReal called %tokens.")
TAG (L"##TableOfReal_tokens [5, \"F1\"]")
DEFINITION (L"gives the value in the cell at the fifth row of the column labelled %F1 of the TableOfReal %tokens.")
TAG (L"##TableOfReal_tokens [\"\\bsct\", \"F1\"]")
DEFINITION (L"gives the value in the cell at the row labelled %%\\bsct% of column %F1 of the TableOfReal %tokens.")
TAG (L"##Table_listeners [3, \"m3ae\"]")
DEFINITION (L"gives the numeric value in the cell at the third row of column %m3ae of the Table %listeners.")
TAG (L"##Table_listeners [3, 12]")
DEFINITION (L"gives the numeric value in the cell at the third row of the 12th column of the Table %listeners.")
TAG (L"##Table_results\\$  [3, \"response\"]")
DEFINITION (L"gives the string value in the cell at the third row of column %response of the Table %results.")
TAG (L"##Table_results\\$  [3, 12]")
DEFINITION (L"gives the string value in the cell at the third row of the 12th column of the Table %results.")
TAG (L"##PitchTier_hello [8]")
DEFINITION (L"gives the pitch (in Hertz) of the 8th point in the PitchTier %hello.")
NORMAL (L"Cells (or samples, or points) outside the objects are considered to contain zeroes.")
ENTRY (L"Interpolation")
NORMAL (L"The values inside some objects can be interpolated.")
TAG (L"##Sound_hello (0.7, 0)")
DEFINITION (L"gives the value (in Pa) at a time of 0.7 seconds in the Sound %hello, by linear interpolation between "
	"the two samples that are nearest to 0.7 seconds. The channels are averaged.")
TAG (L"##Sound_hello (0.7, 1)")
DEFINITION (L"gives the interpolated value (in Pa) at a time of 0.7 seconds in the left channel of the Sound %hello.")
TAG (L"##Sound_hello (0.7, 2)")
DEFINITION (L"gives the interpolated value (in Pa) at a time of 0.7 seconds in the right channel of the Sound %hello.")
TAG (L"##Sound_hello (0.7)")
DEFINITION (L"this can mean various things. In the calculator it means the same as ##Sound_hello (0.7, 0)#, "
	"but in modification formulas it can mean ##Sound_hello (0.7, row)#, where %row refers to the channel. This variation exists in order to make "
	"older Praat scripts (from the time that Praat did not support stereo) compatible with present-day Praat versions; "
	"because of possible confusions, the use of ##Sound_hello (0.7)# is not recommended.")
TAG (L"##Spectrogram_hallo (0.7, 2500)")
DEFINITION (L"gives the value at a time of 0.7 seconds and at a frequency of 2500 Hz in the Spectrogram %hallo, "
	"by linear interpolation between the four samples that are nearest to that point.")
TAG (L"##PitchTier_hullo (0.7)")
DEFINITION (L"gives the pitch (in Hertz) at a time of 0.7 seconds in the PitchTier %hullo.")
NORMAL (L"In the interpolation, times outside the time domain of the objects are considered to contain zeroes (this does not apply to PitchTiers and the like, "
	"which undergo @@constant extrapolation@).")
ENTRY (L"Object contents in a modification formula")
NORMAL (L"Suppose you want to do the difficult way of reversing the contents of a Sound called %hello (the easy way is to choose #Reverse "
	"from the @Modify menu). You select this sound, then choose @@Copy...@ to duplicate it to a new Sound, which you name %%hello_reverse%. "
	"You select this new Sound and choose ##Formula...# from the @Modify menu. The formula will be")
CODE (L"Sound_hello [ncol + 1 - col]")
NORMAL (L"From this example, you see that the indices between [ ] may be formulas themselves, and that you can use implicit attributes like %ncol "
	"and position references like %col. An alternative formula is")
CODE (L"Sound_hello (xmax - x)")
NORMAL (L"at least if %xmin is zero. The advantage of the second method is that is also works correctly if the two sounds have different sampling frequencies; "
	"the disadvantage is that it may do some interpolation between the samples, which deteriorates the sound quality.")
ENTRY (L"Object contents in a script")
NORMAL (L"In scripts, the indices between [ ] and the values between ( ) may be formulas themselves and contain variables. "
	"The following script computes the sum of all the cells along the diagonal of a Matrix named %hello.")
CODE (L"sumDiagonal = 0")
CODE (L"for i to Matrix_hello.ncol")
CODE1 (L"sumDiagonal += Matrix_hello [i, i]")
CODE (L"endfor")
CODE (L"echo The sum of cells along the diagonal is 'sumDiagonal'.")
NORMAL (L"This example could have been written completely with commands from the dynamic menu:")
CODE (L"select Matrix hello")
CODE (L"sumDiagonal = 0")
CODE (L"ncol = Get number of columns")
CODE (L"for i to ncol")
CODE1 (L"value = Get value in cell... i i")
CODE1 (L"sumDiagonal += value")
CODE (L"endfor")
CODE (L"echo The sum of cells along the diagonal is 'sumDiagonal'.")
NORMAL (L"The first version, which accesses the contents directly, is not only three lines shorter, but also three times faster.")
MAN_END

MAN_BEGIN (L"Hidden commands", L"ppgb", 20060920)
NORMAL (L"Some commands in P\\s{RAAT}'s fixed and dynamic menus are hidden by default. "
	"You can still call hidden commands from scripts, run them by clicking on them in a @ButtonEditor, "
	"or make them visible with the help of the @ButtonEditor.")
NORMAL (L"To hide commands that are visible by default, use the @ButtonEditor.")
ENTRY (L"What commands are hidden by default?")
NORMAL (L"Commands that are expected to be of very limited use, are hidden by default. Examples are:")
LIST_ITEM (L"1. The commands @@Add menu command...@, ##Hide menu command...#, ##Show menu command...#, "
	"@@Add action command...@, ##Hide action command...#, and ##Show action command...# in the #Praat menu "
	"of the @@Object window@. These are used in the @@buttons file@ and could be used by an @@initialization script@ or a @@plug-ins|plug-in@ "
	"as well; in an interactive session, however, the functionality of these commands is part of the "
	"@ScriptEditor and the @ButtonEditor.")
LIST_ITEM (L"2. The command ##Read from old Praat picture file...# in the #File menu of the @@Picture window@. "
	"For reading a file format that was in use before May, 1995.")
LIST_ITEM (L"3. In the Praat program, the action ##Sound: Write to Sesam file...#. Writes a file format in common use "
	"in the Netherlands on Vax machines. In the Dutch phonetics departments, the plugs were pulled from the Vaxes in 1994.")
LIST_ITEM (L"4. In the Praat program, the action ##Sound: To Cochleagram (edb)...#. Needed by one person in 1994. "
	"An interesting, but undocumented procedure (De Boer's gamma-tone filter bank plus Meddis & Hewitt's "
	"synapse model), which does not create a normally interpretable Cochleagram object.")
MAN_END

MAN_BEGIN (L"History mechanism", L"ppgb", 20040414)
INTRO (L"The easiest way to do @@scripting@. "
	"The %history is the sequence of all menu commands "
	"(in the Objects or Picture window or in the editors), "
	"action commands (in the dynamic menu), "
	"or mouse clicks on objects (in the list of objects), that you performed during your Praat session, "
	"together with the settings that you specified in the settings windows "
	"that popped up as a result of those commands.")
ENTRY (L"Viewing the history")
NORMAL (L"To view your history, you first open a @ScriptEditor with @@New Praat script@ or @@Open Praat script...@. "
	"You then choose @@Paste history@ from the Edit menu.")
ENTRY (L"Recording a macro")
NORMAL (L"To record a sequence of mouse clicks for later re-use, "
	"perform the following steps:")
LIST_ITEM (L"1. Choose @@Clear history@ from the Edit menu. "
	"This makes the history mechanism forget all previous clicks.")
LIST_ITEM (L"2. Perform the actions that you want to record.")
LIST_ITEM (L"3. Choose @@Paste history@ from the Edit menu. Because you cleared the history "
	"before you started, the resulting script contains only the actions "
	"that you performed in step 2. "
	"You can now already re-run the actions that you performed in step 2.")
LIST_ITEM (L"4. You can save the recorded actions to a script file by choosing #Save from the File menu.")
LIST_ITEM (L"5. You can put this script file under a button in the @@dynamic menu@ "
	"by choosing @@Add to dynamic menu...@ from the File menu, "
	"or under a button in a fixed menu by choosing @@Add to fixed menu...@. "
	"This button will be preserved across Praat sessions.")
NORMAL (L"This macro mechanism is much more flexible than the usual opaque macro mechanism "
	"used by most programs, because you can edit the script and make some "
	"of the arguments variable by putting them in the #form clause at the top of the script. "
	"In this way, the script will prompt the user for these arguments, "
	"just as with all the menu and action commands that end in the three dots (...). "
	"See the @Scripting tutorial for all the things that you can do in scripts.")
MAN_END

MAN_BEGIN (L"initialization script", L"ppgb", 20060920)
INTRO (L"Your initialization script is a normal @@Praat script@ that is run as soon as you start Praat.")
#if defined (UNIX) || defined (macintosh)
NORMAL (L"On Unix or MacOS X, you create an initialization script by creating a file named \"praat-startUp\" "
	"in the directory /usr/local, "
	"or putting a file \".praat-user-startUp\" or \"praat-user-startUp\" in your home directory "
	"(if you rename the Praat executable, these names have to change as well).")
NORMAL (L"If you have more than one of these files, they are run in the above order.")
#elif defined (_WIN32)
NORMAL (L"On Windows NT or XP, you create an initialization script by creating a file named "
	"\"praat-user-startUp\" in your home directory, "
	"which on my Windows XP computer is C:\\bsDocuments and Settings\\bsPaul.")
NORMAL (L"If you have both of these files, they are run in the above order.")
#endif
ENTRY (L"Example")
NORMAL (L"If you like to be greeted by your husband when Praat starts up, "
	"you could put the following lines in your initialization script:")
#if defined (UNIX)
	CODE (L"Read from file... /u/miep/helloMiep.wav")
#elif defined (macintosh)
	CODE (L"Read from file... /Users/miep/helloMiep.wav")
#elif defined (_WIN32)
	CODE (L"Read from file... C:\\bsDocuments and Settings\\bsMiep\\bshelloMiep.wav")
#else
	#error Some audio file reading example should go here
#endif
CODE (L"Play")
CODE (L"Remove")
ENTRY (L"What not to use an initialization script for")
NORMAL (L"You could set preferences like the default font in your initialization script, "
	"but these will be automatically remembered between invocations of Praat anyway (in your @@preferences file@), "
	"so this would often be superfluous.")
NORMAL (L"For installing sets of menu commands at start-up you will probably prefer to use @@plug-ins@ "
	"rather than a single start-up file.")
MAN_END

MAN_BEGIN (L"New Praat script", L"ppgb", 20050822)
INTRO (L"A command in the @@Praat menu@ for creating a new Praat script. "
	"It creates a @ScriptEditor with an empty script that you can edit, run, and save.") 
MAN_END

MAN_BEGIN (L"Open Praat script...", L"ppgb", 20050822)
INTRO (L"A command in the @@Praat menu@ for editing an existing @@Praat script@. "
	"It creates a @ScriptEditor and asks "
	"you to select a file. If you click #%OK, the file is read into the ScriptEditor window, "
	"and you can run and edit it; if you click #%Cancel, you get an empty script, as with @@New Praat script@.") 
MAN_END

MAN_BEGIN (L"Paste history", L"ppgb", 20050822)
INTRO (L"A command in the Edit menu of a @ScriptEditor, for inserting the history of commands. "
	"See @@History mechanism@.")
MAN_END

MAN_BEGIN (L"phonToDifferenceLimens", L"ppgb", 20021215)
INTRO (L"A routine for converting sensation level in phons into intensity difference limen level, "
	"the inverse of @differenceLimensToPhon.")
ENTRY (L"Formula")
FORMULA (L"phonToDifferenceLimens (%phon) = 30 \\.c ((61/60)^^ %phon^ \\-- 1)")
ENTRY (L"Derivation")
NORMAL (L"In first approximation, humans can detect an intensity difference of 1 phon, i.e. "
	"if two sounds that differ only in intensity are played a short time after each other, "
	"people can generally detect their intensity difference if it is greater than 1 phon.")
NORMAL (L"But the sensitivity is somewhat better for louder sounds. "
	"According to @@Jesteadt, Wier & Green (1977)@, the relative difference limen "
	"of intensity is given by")
FORMULA (L"DLI = \\De%I / %I = 0.463 \\.c (%I / %I__0_)^^ \\--0.072^")
NORMAL (L"In this formula, %I is the intensity of the sound in Watt/m^2, %I__0_ is the intensity of "
	"the auditory threshold (i.e. 10^^\\--12^ Watt/m^2 at 1000 Hz), and \\De%I is the just noticeable difference.")
NORMAL (L"@@Boersma (1998)|Boersma (1998: 109)@ calculates a difference-limen scale from this. "
	"Given an intensity %I, the number of difference limens above threshold is ")
FORMULA (L"\\in__%I0_^%I %dx \\De%I(%x) "
	"= (1 / 0.463) \\in__%I0_^%I %dx %I__0_^^\\--0.072^ %x^^0.072\\--1^")
FORMULA (L"= (1 / (0.463\\.c0.072)) ((%I/%I__0_)^^0.072^ \\-- 1)")
NORMAL (L"The sensation level in phon is defined as")
FORMULA (L"SL = 10 log__10_ (%I/%I__0_)")
NORMAL (L"so that the number of difference limens above threshold is")
FORMULA (L"(1 / (0.463\\.c0.072)) (10^^(0.072/10)(10log(%I/%I__0_))^ \\-- 1) "
	"= 30 \\.c (1.0167^^SL^ \\-- 1)")
MAN_END

MAN_BEGIN (L"plug-ins", L"ppgb", 20070129)
INTRO (L"Experienced Praat script writers can distribute their product as a plug-in to Praat.")
ENTRY (L"The Praat plug-in mechanism")
NORMAL (L"When Praat starts up, it will execute all Praat scripts called ##setup.praat# "
	"that reside in directories whose name starts with ##plugin_# and that themselves reside in "
	"your Praat @@preferences directory@.")
ENTRY (L"How to write a Praat plug-in")
NORMAL (L"Suppose that you have a set of Praat scripts specialized in the analysis and synthesis of vocalizations of guinea pigs, "
	"and that these scripts are called ##analyseQueak.praat# and ##createQueak.praat# (\"queak\" is what guinea pigs tend to say). "
	"With the @ScriptEditor, you have put the script ##analyseQueak.praat# in the dynamic menu that "
	"appears if the user selects a Sound object, and you have put the script ##createQueak.praat# in the @@New menu@. "
	"Only the latter script requires the user to supply some settings in a form, so the two menu commands "
	"are ##Analyse queak# (without dots) and ##Create queak...# (with three dots), respectively. "
	"Suppose now that you want to distribute those two commands to other guinea pig vocalization researchers.")
NORMAL (L"What you do is that you create a Praat script called ##setup.praat# (in the same directory as the two other scripts), "
	"that contains the following two lines:")
CODE (L"@@Add action command...@ Sound 1 \"\" 0 \"\" 0 \"Analyse queak\" \"\" 0 analyseQueak.praat")
CODE (L"@@Add menu command...@ Objects New \"Create queak...\" \"\" 0 createQueak.praat")
NORMAL (L"(If you ran this script, Praat would install those two commands in the correct menus, and remember them in the @@buttons file@; "
	"but you are now going to install them in a different way.)")
NORMAL (L"You now put the three scripts in a new directory called ##plugin_Queak#, "
	"and put this directory in your Praat preferences directory. If you are on Windows, "
	"you will now have a directory called something like ##C:\\bsDocuments and Settings\\bsYour Name\\bsPraat\\bsplugin_Queak#.")
NORMAL (L"If you now start up Praat, Praat will automatically execute the script "
	"##C:\\bsDocuments and Settings\\bsYour Name\\bsPraat\\bsplugin_Queak\\bssetup.praat# "
	"and thereby install the two buttons. The two buttons will %not be remembered in the buttons file, "
	"but they will be installed at every Praat start-up. De-installation involves removing (or renaming) the ##plugin_Queak# directory.")
NORMAL (L"To distribute the Queak plug-in among your colleague guinea pig researchers, you can use any installer program to put "
	"the ##plugin_Queak# directory into the user's Praat preferences directory; or you could ask those colleagues to move "
	"the ##plugin_Queak# directory there by hand.")
ENTRY (L"The structure of your plug-in directory")
NORMAL (L"In the example ##setup.praat# file above, the names of the scripts ##analyseQueak.praat# and ##createQueak.praat# "
	"occur without any directory information. This works because Praat regards these file names as being relative to the directory "
	"where ##setup.praat# is located. If your plug-in is much larger than two scripts, you may want to put subdirectories into "
	"the directory ##plugin_Queak#. For instance, if you put ##analyseQueak.praat# into the subdirectory ##analysis#, "
	"your line in the ##setup.praat# script would look as follows:")
CODE (L"@@Add action command...@ Sound 1 \"\" 0 \"\" 0 \"Analyse queak\" \"\" 0 analysis/analyseQueak.praat")
NORMAL (L"The forward slash (\"/\") in this example makes your plug-in platform-independent: it will work unchanged "
	"on Windows, Macintosh, and Unix.")
NORMAL (L"Nothing prevents you from adding data files to your plug-in. For instance, your ##plugin_Queak# directory "
	"could contain a subdirectory #sounds full of guinea pig recordings, and you could make them available in the New or Read menu.")
ENTRY (L"Using a plug-in for site-wide customization")
NORMAL (L"If your local guinea pig research group shares a number of Praat scripts, these can be made available to everybody "
	"in the following way:")
LIST_ITEM (L"1. Create a script that adds buttons to the fixed and dynamic menus, using the commands "
	"@@Add menu command...@ and @@Add action command...@. This script could be a slightly edited copy of someone's "
	"@@buttons file@.")
LIST_ITEM (L"2. Put this script where everybody can see it, "
	"for instance in ##U:\\bsMaldenGuineaPigResearchButtons.praat#, where U is your shared computer.")
LIST_ITEM (L"3. Create a file ##setup.praat# that contains only the following line:")
CODE1 (L"execute U:\\bsMaldenGuineaPigResearchButtons.praat")
LIST_ITEM (L"4. Put the ##setup.praat# file in a new directory called ##plugin_MaldenGuineaPigResearch#, "
	"and distribute this directory among your local colleagues.")
NORMAL (L"This procedure allows all members of the group to automatically enjoy all the later changes in your "
	"custom command set.")
MAN_END

MAN_BEGIN (L"plugins", L"ppgb", 20060920)
INTRO (L"See @@plug-ins@.")
MAN_END

MAN_BEGIN (L"Praat script", L"ppgb", 19980824)
INTRO (L"An executable text that consists of menu commands and action commands.")
NORMAL (L"See the @Scripting tutorial.")
MAN_END

MAN_BEGIN (L"preferences directory", L"ppgb", 20070129)
INTRO (L"The Praat preferences directory is the directory where Praat saves the @@preferences file@ and the @@buttons file@, "
	"and where you can install @@plug-ins@. "
	"If the preferences directory does not exist, it will automatically be created when you start Praat.")
ENTRY (L"Unix")
NORMAL (L"If your home directory is ##/people/miep/#, your Praat preferences directory will be ##/people/miep/.praat-dir/#.")
ENTRY (L"Macintosh")
NORMAL (L"If you are user #miep, your Praat preferences directory will be ##/Users/miep/Library/Preferences/Praat Prefs/#.")
ENTRY (L"Windows")
NORMAL (L"If you are user #Miep, your Praat preferences directory will be ##C:\\bsDocuments and Settings\\bsMiep\\bsPraat\\bs#.")
MAN_END

MAN_BEGIN (L"preferences file", L"ppgb", 20071205)
NORMAL (L"The file into which some of your preferences are saved across your sessions with Praat. "
	"For instance, if you change the font used by the Picture window to Palatino and quit Praat, "
	"the Picture-window font will still be Palatino when you start Praat again.")
NORMAL (L"The preferences file is written to disk when you quit Praat, "
	"and it is read when you start Praat. It is a simple text file that you can read "
	"(but should not edit) with any text editor.")
ENTRY (L"Where is the preferences file?")
NORMAL (L"The preferences file is in your Praat @@preferences directory@.")
NORMAL (L"On Unix the file is called #prefs5, "
	"for instance ##/people/miep/.praat-dir/prefs5#.")
NORMAL (L"On Macintosh it is called #Prefs5, "
	"for instance ##/Users/miep/Library/Preferences/Praat Prefs/Prefs5#.")
NORMAL (L"On Windows it is called ##Preferences5.ini#, "
	"for instance ##C:\\bsDocuments and Settings\\bsMiep\\bsPraat\\bsPreferences5.ini#.")
MAN_END

MAN_BEGIN (L"Run script...", L"ppgb", 20050822)
INTRO (L"A hidden command in the @@Praat menu@. Runs a @@Praat script@.")
ENTRY (L"Usage")
NORMAL (L"This command is hidden because you would normally open a script "
	"with @@Open Praat script...@, so that you can run it several times without "
	"selecting a file each time.")
NORMAL (L"In scripts, the command ##%%Run script...#% is automatically replaced "
	"by the script directive #execute.")
MAN_END

MAN_BEGIN (L"Scripting", L"ppgb", 20080106)
INTRO (L"This is one of the tutorials of the P\\s{RAAT} program. It assumes you are familiar with the @Intro.")
NORMAL (L"A %script is a text that consists of menu commands and action commands. "
	"If you %run the script (perhaps from a @ScriptEditor), "
	"the commands are executed as if you clicked on them.")
NORMAL (L"You can read this tutorial sequentially with the help of the \"< 1\" and \"1 >\" buttons.")
LIST_ITEM (L"@@Scripting 1. My first script@ (how to create, how to run)")
LIST_ITEM (L"@@Scripting 2. Arguments to commands@ (numeric, check, radio, text, file)")
LIST_ITEM (L"@@Scripting 3. Layout@ (white space, comments, continuation lines)")
LIST_ITEM (L"@@Scripting 4. Object selection@ (selecting and querying)")
LIST_ITEM (L"@@Scripting 5. Language elements@")
LIST_ITEM1 (L"@@Scripting 5.1. Variables@ (numeric, string, copy, substitution)")
LIST_ITEM1 (L"@@Scripting 5.2. Formulas@ (numeric, string)")
LIST_ITEM1 (L"@@Scripting 5.3. Jumps@ (if, then, elsif, else, endif)")
LIST_ITEM1 (L"@@Scripting 5.4. Loops@ (for/endfor, while/endwhile, repeat/until)")
LIST_ITEM1 (L"@@Scripting 5.5. Procedures@ (call, procedure)")
LIST_ITEM1 (L"@@Scripting 5.6. Arrays")
LIST_ITEM1 (L"@@Scripting 5.7. Including other scripts")
LIST_ITEM1 (L"@@Scripting 5.8. Quitting@ (exit)")
LIST_ITEM (L"@@Scripting 6. Communication outside the script")
LIST_ITEM1 (L"@@Scripting 6.1. Arguments to the script@ (form/endform, execute)")
LIST_ITEM1 (L"@@Scripting 6.2. Writing to the Info window@ (echo, print, printtab, printline)")
LIST_ITEM1 (L"@@Scripting 6.3. Query commands@ (Get, Count)")
LIST_ITEM1 (L"@@Scripting 6.4. Files@ (fileReadable, <, >, >>, filedelete, fileappend)")
LIST_ITEM1 (L"@@Scripting 6.5. Calling system commands@ (system, environment\\$ , stopwatch)")
LIST_ITEM1 (L"@@Scripting 6.6. Controlling the user@ (pause)")
LIST_ITEM1 (L"@@Scripting 6.7. Sending a message to another program@ (sendsocket)")
LIST_ITEM1 (L"@@Scripting 6.8. Messages to the user@ (exit, assert, nowarn, nocheck)")
LIST_ITEM1 (L"@@Scripting 6.9. Calling from the command line")
LIST_ITEM (L"@@Scripting 7. Scripting the editors")
LIST_ITEM1 (L"@@Scripting 7.1. Scripting an editor from a shell script@ (editor/endeditor)")
LIST_ITEM1 (L"@@Scripting 7.2. Scripting an editor from within")
LIST_ITEM (L"@@Scripting 8. Controlling Praat from another program")
LIST_ITEM1 (L"@@Scripting 8.1. The sendpraat subroutine")
LIST_ITEM1 (L"@@Scripting 8.2. The sendpraat program")
LIST_ITEM1 (L"@@Scripting 8.3. The sendpraat directive")
NORMAL (L"Also see the @@scripting examples@.")
MAN_END

MAN_BEGIN (L"Scripting 1. My first script", L"ppgb", 20050822)
NORMAL (L"Suppose that you want to create a script that allows you to play a selected Sound object twice. "
	"You first create an empty script, by choosing @@New Praat script@ from the Praat menu. "
	"A @ScriptEditor will appear on your screen. In this editor, you type")
CODE (L"Play")
CODE (L"Play")
NORMAL (L"Now select a #Sound in the object menu. As you expect from selecting a Sound, a #Play button will "
	"appear in the dynamic menu. If you now choose #Run in the ScriptEditor, the sound "
	"will be played twice.")
ENTRY (L"What commands can I put into my script?")
NORMAL (L"In the above example, you could use the \"Play\" command because that was "
	"the text on a button currently available button in the dynamic menu. "
	"Apart from these selection-dependent (dynamic) commands, "
	"you can also use all fixed commands in the menus of the @@Object window@ "
	"and the @@Picture window@. For how to proceed with commands that need %arguments "
	"(i.e. the commands that end in \"...\" and present a settings window), "
	"see @@Scripting 2. Arguments to commands|\\SS2@.")
ENTRY (L"Faster ways of getting a script text")
NORMAL (L"Instead of manually typing the command lines, as described above, it may be easier "
	"to create a script text from a %%macro recording%, with the @@History mechanism@. "
	"This allows you to create script texts without typing. "
	"For instance, if you choose @@Clear history@ in your ScriptEditor, then click the #%Play button twice (after selecting a Sound), "
	"and then choose @@Paste history@, your new script text "
	"contains exactly two lines that read \"Play\".")
NORMAL (L"To edit a script that is already contained in a file on disk, use @@Open Praat script...@.")
ENTRY (L"How to run a script")
NORMAL (L"You can run scripts from the @ScriptEditor. If you will have to use the script very often, "
	"it is advisable to create a button for it in the fixed menu or in a dynamic menu. See the "
	"@ScriptEditor manual page.")
NORMAL (L"On Unix and Windows, you can also run scripts from the command line. See @@Scripting 6.9. Calling from the command line@.")
MAN_END

MAN_BEGIN (L"Scripting 2. Arguments to commands", L"ppgb", 20041229)
INTRO (L"This chapter describes how your script should represent "
	"commands that need %arguments, i.e. commands whose button has a title that ends in \"...\". "
	"Clicking such a button normally presents a %%settings window%, which asks the user to supply "
	"%arguments (settings) and then press the OK button. In a script, all of these arguments should be supplied on the same "
	"line as the command, in the same order as in the settings window, counted from top to bottom.")
ENTRY (L"Numeric arguments")
NORMAL (L"The command ##Draw line...# from the World menu in the Picture window, "
	"normally presents a settings window that asks the user to supply values for the numeric parameters %%From x%, "
	"%%From y%, %%To x%, and %%To y% (from top to bottom). To draw a line from the point (0, 0.5) "
	"to the point (1, 1), the values of the arguments would be 0, 0.5, 1, and 1, respectively. "
	"In a script, the command would read")
CODE (L"Draw line... 0 0.5 1 1")
ENTRY (L"Check buttons")
NORMAL (L"In a script, you represent a %%check button% (yes/no choice) by \"true\" or \"false\", "
	"which may be abbreviated to \"t\" etc., or written with a capital; "
	"\"yes\" or \"no\" can also be used, as well as \"1\" or \"0\":")
CODE (L"Marks left every... 1.0 100 yes yes no")
ENTRY (L"Radio boxes")
NORMAL (L"You represent a %%radio box% (multiple choice) by the text on the button that you want to select:")
CODE (L"Print picture to PostScript printer... Finest A4 Portrait 1.0")
NORMAL (L"If the choice (in a non-final argument) contains spaces, it should be enclosed within double quotes:")
CODE (L"Print picture to PostScript printer... Finest \"US Letter\" Portrait 1.0")
NORMAL (L"Using these double quotes is necessary because spaces are normally used for separating the arguments. "
	"Putting quotes around \"US Letter\" ensures that the second argument consists of both words. "
	"If you forget the quotes, the interpreter will think that the second argument is \"US\", "
	"the third argument is \"Letter\", and the fourth argument is the rest of the line, namely \"Portrait 1.0\", "
	"and the command will fail with the message")
CODE (L"`Paper size' cannot have the value \"US\".")
ENTRY (L"Text arguments")
NORMAL (L"A text argument at the end should be typed without any quotes:")
CODE (L"Text... 400 Centre 1.5 Bottom This is the summit")
NORMAL (L"Though spaces separate the arguments, the last argument is always written without surrounding "
	"quotes, even if it contains spaces. This is possible because the interpreter knows that the ##Text...# "
	"command takes five arguments. The fifth argument is simply everything that follows the first four "
	"arguments. With this strategy, you will not suffer from %%quote paranoia%, which would occur "
	"if your text itself contains quotes:")
CODE (L"Text... 0.5 Centre 0.5 Half \"hello world\"")
NORMAL (L"In this case, the quotes around \"hello world\" will be written to the Picture window as well.")
NORMAL (L"For these reasons, nearly all texts in settings windows appear in the last (bottom) field, "
	"so that it can be scripted without using quotes. The exceptions are those few commands that "
	"have more than a single text parameter. A text argument that is not at the end should then be enclosed "
	"in double quotes if it is empty or contains spaces (otherwise, the quotes are optional):")
CODE (L"Add menu command... Objects New \"Create a Bicycle...\" \"\" 0 /u/miep/createBicycle.script")
NORMAL (L"If you want to include a double quote in such a text, use %two double quotes:")
CODE (L"Add menu command... Objects New \"Create a \\\"l\\\"lBicycle\\\"r\\\"r...\" (etc.)")
NORMAL (L"This doubling of quotes is what you want to avoid in your scripts, especially if your "
	"texts come from the expansion of string variables.")
ENTRY (L"File arguments")
NORMAL (L"The commands from the Read and Write menus, and several other commands whose names "
	"start with Read, Open, or Write, present a %%file selector window% instead of a typical Praat "
	"settings window. File selector windows ask the user to supply a single argument: the file name.")
#if defined (UNIX)
	NORMAL (L"In a script, you can supply the complete %path, including the directory (folder) hierarchy "
	"and the name of the file. On Unix, it goes like this (if you are user \"miep\"):")
	CODE (L"Read from file... /home/miep/sounds/animals/miauw.aifc")
	NORMAL (L"or just")
	CODE (L"Read from file... ~/sounds/animals/miauw.aifc")
	NORMAL (L"where \"~\" is the Unix way to refer to your home directory.")
#elif defined (macintosh)
	NORMAL (L"In a script, you can supply the complete %path, including the directory (folder) hierarchy "
	"and the name of the file. On MacOS X, it goes like this (if you are user \"miep\"):")
	CODE (L"Read from file... /Users/miep/Sounds/Animals/miauw.aifc")
	NORMAL (L"or just")
	CODE (L"Read from file... ~/Sounds/Animals/miauw.aifc")
	NORMAL (L"where \"~\" is the Unix way to refer to your home directory. If your file is on the desktop, the command would be:")
	CODE (L"Read from file... /Users/miep/Desktop/miauw.aifc")
	NORMAL (L"or just")
	CODE (L"Read from file... ~/Desktop/miauw.aifc")
	NORMAL (L"If your Sounds folder is on a USB drive called Miep, it would be:")
	CODE (L"Read from file... /Volumes/Miep/Sounds/Animals/miauw.aifc")
#elif defined (_WIN32)
	NORMAL (L"In a script, you can supply the complete %path, including the directory (folder) hierarchy "
	"and the name of the file. In Windows, it goes like this:")
	CODE (L"Read from file... D:\\bsSounds\\bsAnimals\\bsmiauw.aifc")
#else
	#error Supply an example complete path to a sound file
#endif
NORMAL (L"Instead of these complete path names, you can use %relative path names. "
	"These are taken as relative to the directory in which your script resides.")
#if defined (UNIX)
	NORMAL (L"On Unix, a relative path name starts without a \"/\". So if your script is "
		"%%/home/miep/sounds/analysis.praat%, the above line could be")
	CODE (L"Read from file... animals/miauw.aifc")
	NORMAL (L"Finally, your script may not be in a directory %above the directory from which you "
		"like to read, but in a directory on the side, like /home/miep/scripts. The command would then read")
	CODE (L"Read from file... ../animals/miauw.aifc")
#elif defined (macintosh)
	NORMAL (L"On MacOS X, a relative path name starts without a \"/\". So if your script is "
		"%%/Users/miep/Sounds/analysis.praat%, the above line could be")
	CODE (L"Read from file... Animals/miauw.aifc")
	NORMAL (L"Finally, your script may not be in a directory %above the directory from which you "
		"like to read, but in a directory on the side, like /Users/miep/scripts. The command would then read")
	CODE (L"Read from file... ../Animals/miauw.aifc")
#elif defined (_WIN32)
	NORMAL (L"In Windows, a relative path name starts without a backslash. So if your script is "
		"C:\\bsSounds\\bsAnalysis.praat, the sound file is read by")
	CODE (L"Read from file... Animals\\bsmiauw.aifc")
	NORMAL (L"Finally, your script may not be in a directory %above the directory from which you "
		"like to read, but in a directory on the side, like D:\\bsScripts. The commands would then read")
	CODE (L"Read from file... ..\\bsAnimals\\bsmiauw.aifc")
#else
	#error Supply an example partial path to a sound file
#endif
ENTRY (L"How to supply arguments automatically")
NORMAL (L"If you dislike manually copying arguments from settings windows into your script, "
	"you can use the @@history mechanism@ to automate this process: "
	"choose @@Clear history@ from the Edit menu in your @ScriptEditor, "
	"click your command button, edit the arguments, and click OK. The command will be executed. "
	"Then choose @@Paste history@, and the command line, including the arguments (with correct quotes), "
	"appears in a the ScriptEditor. You can build a new script on the basis of this line.")
MAN_END

MAN_BEGIN (L"Scripting 3. Layout", L"ppgb", 20070419)
INTRO (L"This chapter handles the way you use white space, comments, "
	"and continuation lines in a Praat script.")
ENTRY (L"White space")
NORMAL (L"All white space (spaces and tabs) at the beginning of lines is ignored. This means that you can "
	"use indenting to make your script readable. You are advised to use three spaces for each level of indenting:")
CODE (L"sum = 0")
CODE (L"for i to 10")
CODE (L"   for j to 10")
CODE (L"      sum += i\\^ j")
CODE (L"   endfor")
CODE (L"endfor")
CODE (L"echo The sum of the products is 'sum'")
NORMAL (L"Lines that are empty or consist solely of white space, are also ignored.")
ENTRY (L"Comments")
NORMAL (L"Comments are lines that start with !, \\# , or ;. These lines are ignored when your script is running:")
CODE (L"\\#  Create 1 second of a sine wave with a frequency of 100 Hertz,")
CODE (L"\\#  sampled at 44100 Hz:")
CODE (L"Create Sound from formula... sine Mono 0 1 44100 sin (2*pi*100*x)")
ENTRY (L"Continuation lines")
NORMAL (L"There is normally one line per command, and one command per line.")
NORMAL (L"But you can chop up long lines by using continuaton lines that start with three dots:")
CODE (L"Create Sound from formula... windowedSine Mono 0 1 44100")
CODE (L"   ... 0.5 * sin(2*pi*1000*x) * exp(-0.5*((x-0.5)/0.1)\\^ 2)")
NORMAL (L"You will normally want to follow such an %ellipsis with a space, unless you want to concatenate "
	"the parts of a long word:")
CODE (L"Viewport... 0 10 0 4")
CODE (L"Text top... yes It's a long way to Llanfairpwllgwyngyll")
CODE (L"   ...gogerychwyrndrobwllllantysiliogogogoch,")
CODE (L"   ... unless you start from Tyddyn-y-felin.")
MAN_END

MAN_BEGIN (L"Scripting 4. Object selection", L"ppgb", 20070419)
INTRO (L"This chapter is about how to select objects from your script, "
	"and how to find out what objects are currently selected.")
ENTRY (L"Selecting objects")
NORMAL (L"To simulate the mouse-clicked and dragged selection in the list of objects, "
	"you have the following commands:")
TAG (L"#select %object")
DEFINITION (L"selects one object, and deselects all others. If there are more "
	"objects with the same name, the most recently created one "
	"(i.e., the one nearest to the bottom of the list of objects) is selected:")
CODE1 (L"#select Sound hallo")
CODE1 (L"Play")
TAG (L"#plus %object")
DEFINITION (L"adds one object to the current selection.")
TAG (L"#minus %object")
DEFINITION (L"removes one object from the current selection.")
TAG (L"##select all")
DEFINITION (L"selects all objects:")
CODE1 (L"##select all")
CODE1 (L"Remove")
NORMAL (L"In the Praat shell, newly created objects are automatically selected. "
	"This is also true in scripts:")
CODE (L"! Generate a sine wave, play it, and draw its spectrum.")
CODE (L"Create Sound from formula... sine377 Mono 0 1 44100   0.9 * sin (2*pi*377*x)")
CODE (L"Play")
CODE (L"To Spectrum")
CODE (L"! Draw the Spectrum:")
CODE (L"Draw... 0 5000 20 80 yes")
CODE (L"! Remove the created Spectrum and Sound:")
CODE (L"#plus Sound sine377")
CODE (L"Remove")
NORMAL (L"Instead of by name, you can also select objects by their sequential ID:")
CODE (L"#select 43")
NORMAL (L"This selects the 43rd object that you created since you started the program (see below).")
ENTRY (L"Querying selected objects")
NORMAL (L"You can get the name of a selected object into a string variable. "
	"For instance, the following reads the name of the second selected Sound "
	"(as counted from the top of the list of objects) into the variable %name\\$ :")
CODE (L"name\\$  = ##selected\\$ # (\"Sound\", 2)")
NORMAL (L"If the Sound was called \"Sound hallo\", the variable %name\\$  will contain the string \"hallo\". "
	"To get the name of the topmost selected Sound object, you can leave out the number:")
CODE (L"name\\$  = ##selected\\$ # (\"Sound\")")
NORMAL (L"To get the full name (type + name) of the third selected object, you do:")
CODE (L"fullName\\$  = ##selected\\$ # (3)")
NORMAL (L"To get the full name of the topmost selected object, you do:")
CODE (L"fullName\\$  = ##selected\\$ # ()")
NORMAL (L"To get the type and name out of the full name, you do:")
CODE (L"type\\$  = extractWord\\$  (fullName\\$ , \"\")")
CODE (L"name\\$  = extractLine\\$  (fullName\\$ , \" \")")
NORMAL (L"Negative numbers count from the bottom. Thus, to get the name of the bottom-most selected Sound "
	"object, you say")
CODE (L"name\\$  = ##selected\\$ # (\"Sound\", -1)")
NORMAL (L"You would use ##selected\\$ # for drawing the object name in a picture:")
CODE (L"Draw... 0 0 0 0 yes")
CODE (L"name\\$  = ##selected\\$ # (\"Sound\")")
CODE (L"Text top... no This is sound 'name\\$ '")
NORMAL (L"For identifying previously selected objects, this method is not very suitable, since "
	"there may be multiple objects with the same name:")
CODE (L"\\#  The following two lines are OK:")
CODE (L"soundName\\$  = ##selected\\$ # (\"Sound\", -1)")
CODE (L"pitchName\\$  = ##selected\\$ # (\"Pitch\")")
CODE (L"\\#  But the following line is questionable, since it doesn't")
CODE (L"\\#  necessarily select the previously selected Sound again:")
CODE (L"#select Pitch 'pitchName\\$ '")
NORMAL (L"Instead of this error-prone approach, you should get the object's unique ID. "
	"The correct version of our example becomes:")
CODE (L"sound = #selected (\"Sound\", -1)")
CODE (L"pitch = #selected (\"Pitch\")")
CODE (L"\\#  Correct:")
CODE (L"#select pitch")
NORMAL (L"To get the number of selected Sound objects into a variable, use")
CODE (L"numberOfSelectedSounds = numberOfSelected (\"Sound\")")
NORMAL (L"To get the number of selected objects into a variable, use")
CODE (L"numberOfSelectedObjects = numberOfSelected ()")
ENTRY (L"Example: doing something to every selected Sound")
CODE (L"n = numberOfSelected (\"Sound\")")
CODE (L"for i to n")
CODE1 (L"sound'i' = selected (\"Sound\", i)")
CODE (L"endfor")
CODE (L"\\#  Median pitches of all selected sounds:")
CODE (L"for i to n")
CODE1 (L"select sound'i'")
CODE1 (L"To Pitch... 0.0 75 600")
CODE1 (L"f0 = Get quantile... 0 0 0.50 Hertz")
CODE1 (L"Remove")
CODE (L"endfor")
CODE (L"\\#  Restore selection:")
CODE (L"if n >= 1")
CODE1 (L"select sound1")
CODE1 (L"for i from 2 to n")
CODE2 (L"plus sound'i'")
CODE1 (L"endfor")
CODE (L"endif")
ENTRY (L"A shortcut")
NORMAL (L"Instead of")
CODE (L"Create Sound from formula... sine Mono 0 1 44100 0.5*sin(2*pi*1000*x)")
CODE (L"sound = selected (\"Sound\")")
NORMAL (L"you can just write")
CODE (L"sound = Create Sound from formula... sine Mono 0 1 44100 0.5*sin(2*pi*1000*x)")
NORMAL (L"and instead of")
CODE (L"To Pitch... 0.0 75 600")
CODE (L"pitch = selected (\"Pitch\")")
NORMAL (L"you can write")
CODE (L"pitch = To Pitch... 0.0 75 600")
NORMAL (L"This only works if the command creates a single object.")
MAN_END

MAN_BEGIN (L"Scripting 5. Language elements", L"ppgb", 20021218)
NORMAL (L"In a Praat script, you can use variables, expressions, and functions, of numeric as well as string type, "
	"and most of the control structures known from other procedural computer languages. "
	"The way the distinction between numbers and strings is made, may remind you of the programming language Basic.")
LIST_ITEM (L"@@Scripting 5.1. Variables@ (numeric, string, copy, expansion)")
LIST_ITEM (L"@@Scripting 5.2. Formulas@ (numeric, string)")
LIST_ITEM (L"@@Scripting 5.3. Jumps@ (if, then, elsif, else, endif)")
LIST_ITEM (L"@@Scripting 5.4. Loops@ (for/endfor, while/endwhile, repeat/until)")
LIST_ITEM (L"@@Scripting 5.5. Procedures@ (call, procedure)")
LIST_ITEM (L"@@Scripting 5.6. Arrays@")
LIST_ITEM (L"@@Scripting 5.7. Including other scripts@")
LIST_ITEM (L"@@Scripting 5.8. Quitting@ (exit)")
MAN_END

MAN_BEGIN (L"Scripting 5.1. Variables", L"ppgb", 20080515)
INTRO (L"In a Praat script, you can use numeric variables as well as string variables.")
ENTRY (L"Numeric variables")
NORMAL (L"Numeric variables contain integer numbers between -1,000,000,000,000,000 and +1,000,000,000,000,000 "
	"or real numbers between -10^^308^ and +10^^308^. The smallest numbers lie near -10^^-308^ and +10^^-308^.")
NORMAL (L"You can use %%numeric variables% in your script:")
TAG (L"%variable = %formula")
DEFINITION (L"evaluates a numeric formula and assign the result to a variable.")
NORMAL (L"Example:")
CODE (L"length = 10")
CODE (L"Draw line... 0 length 1 1")
NORMAL (L"Names of numeric variables must start with a lower-case letter, optionally followed by a sequence "
	"of letters, digits, and underscores.")
ENTRY (L"String variables")
NORMAL (L"You can also use %%string variables%, which contain text:")
CODE (L"title\\$  = \"Dutch nasal place assimilation\"")
NORMAL (L"As in the programming language Basic, the names of string variables end in a dollar sign.")
ENTRY (L"Variable substitution")
NORMAL (L"Existing variables are substituted when put between quotes:")
CODE (L"x = 99")
CODE (L"x2 = x * x")
CODE (L"echo The square of 'x' is 'x2'.")
NORMAL (L"This will write the following text to the Info window:")
CODE (L"The square of 99 is 9801.")
NORMAL (L"You can reduce the number of digits after the decimal point by use of the colon:")
CODE (L"root = sqrt (2)")
CODE (L"echo The square root of 2 is approximately 'root:3'.")
NORMAL (L"This will write the following text to the Info window:")
CODE (L"The square root of 2 is approximately 1.414.")
NORMAL (L"By using \":0\", you round to whole values:")
CODE (L"root = sqrt (2)")
CODE (L"echo The square root of 2 is very approximately 'root:0'.")
NORMAL (L"This will write the following text to the Info window:")
CODE (L"The square root of 2 is very approximately 1.")
NORMAL (L"By using \":3\\% \", you give the result in a percent format:")
CODE (L"jitter = 0.0156789")
CODE (L"echo The jitter is 'jitter:3\\% '.")
NORMAL (L"This will write the following text to the Info window:")
CODE (L"The jitter is 1.568\\% .")
NORMAL (L"The number 0, however, will always be written as 0, and for small numbers the number of "
	"significant digits will never be less than 1:")
CODE (L"jitter = 0.000000156789")
CODE (L"echo The jitter is 'jitter:3\\% '.")
NORMAL (L"This will write the following text to the Info window:")
CODE (L"The jitter is 0.00002\\% .")
#define xstr(s) str(s)
#define str(s) #s
NORMAL (L"Some ##predefined numeric variables# are $macintosh, $windows, and $unix, which are 1 if the script "
	"is running on a Macintosh, Windows, or Unix platform (respectively), and which are otherwise zero. "
	"Another one is $praatVersion, which is e.g. " xstr(PRAAT_VERSION_NUM) " for the current version of Praat.")
NORMAL (L"Some ##predefined string variables# are $$newline\\$ $,  $$tab\\$ $, and $$shellDirectory\\$ $. "
	"The last one specifies the directory that was the default directory when Praat started up; "
	"you can use it in scripts that run from the Unix or DOS command line. "
	"Likewise, there exist the predefined string variables $$homeDirectory\\$ $, "
	"$$preferencesDirectory\\$ $, and $$temporaryDirectory\\$ $. These three refer to your home directory "
	"(which is where you log in), the Praat @@preferences directory@, and a directory for saving temporary files; "
	"if you want to know what they are on your computer, try to #echo them in a script window. "
	"The variable $$defaultDirectory\\$ $ is available for formulas in scripts; it is the directory that contains the script file. "
	"Finally, we have $$praatVersion\\$ $, which is \"" xstr(PRAAT_VERSION_STR) "\" for the current version of Praat.")
MAN_END
/*
form Convert from WAV to AIFF
   text fileName hello.wav
endform
fileName$ = fileName$ - ".wav"
Read from file... 'shellDirectory$'/'fileName$'.wav
Write to AIFF file... 'shellDirectory$'/'fileName$'.aiff

if left$ (fileName$) <> "/"
   fileName$ = 'shellDirectory$'/'fileName$'
endif
*/

MAN_BEGIN (L"Scripting 5.2. Formulas", L"ppgb", 20021218)
INTRO (L"In a Praat script, you can use numeric expressions as well as string expressions.")
ENTRY (L"Numeric expressions")
NORMAL (L"You can use a large variety of @@Formulas@ in your script:")
CODE1 (L"length = 10")
CODE1 (L"height = length/2")
CODE1 (L"area = length * height")
NORMAL (L"You can use numeric variables and formulas in arguments to commands:")
CODE1 (L"Draw line... 0 length 0 length/2")
NORMAL (L"Of course, all arguments except the last should either not contain spaces, "
	"or be enclosed in double quotes. So you would write either")
CODE1 (L"Draw line... 0 height*2 0 height")
NORMAL (L"or")
CODE1 (L"Draw line... 0 \"height * 2\" 0 height")
NORMAL (L"You can use numeric expressions in assignments (as above), or after "
	"#if, #elsif, #while, #until, and twice after #for.")
NORMAL (L"On how to get information from commands that normally write to the Info window, "
	"see @@Scripting 6.3. Query commands@.")
MAN_END

MAN_BEGIN (L"Scripting 5.3. Jumps", L"ppgb", 19991112)
NORMAL (L"You can use conditional jumps in your script:")
TAG (L"#if %expression")
TAG (L"#elsif %expression")
DEFINITION (L"if the expression evaluates to zero or %false, the execution of the script jumps to the next "
	"#elsif or after the next #else or #endif at the same depth..")
NORMAL (L"The following script computes the preferred length of a bed for a person 'age' years of age:")
CODE (L"#if age <= 3")
CODE (L"   length = 1.20")
CODE (L"#elsif age <= 8")
CODE (L"   length = 1.60")
CODE (L"#else")
CODE (L"   length = 2.00")
CODE (L"#endif")
NORMAL (L"A variant spelling for #elsif is #elif.")
MAN_END

MAN_BEGIN (L"Scripting 5.4. Loops", L"ppgb", 20070225)
ENTRY (L"\"For\" loops")
TAG (L"#for %variable #from %expression__1_ #to %expression__2_")
TAG (L"#for %variable #to %expression")
DEFINITION (L"the statements between the #for line and the matching #endfor will be executed "
	"while a variable takes on values between two expressions, with an increment of 1 "
	"on each turn of the loop. The default starting value of the loop variable is 1.")
NORMAL (L"The following script plays nine sine waves, with frequencies of 200, 300, ..., 1000 Hz:")
CODE (L"#for i #from 2 #to 10")
CODE (L"   frequency = i * 100")
CODE (L"   Create Sound from formula... tone Mono 0 0.3 44100 0.9*sin(2*pi*frequency*x)")
CODE (L"   Play")
CODE (L"   Remove")
CODE (L"#endfor")
NORMAL (L"The stop value of the #for loop is evaluated on each turn. If the second expression "
	"is already less than the first expression to begin with, the statements between #for and #endfor "
	"are not executed even once.")
ENTRY (L"\"Repeat\" loops")
TAG (L"#until %expression")
DEFINITION (L"the statements between the matching preceding #repeat and the #until line "
	"will be executed again if the expression evaluates to zero or %false.")
NORMAL (L"The following script measures the number of trials it takes me to throw 12 with two dice:")
CODE (L"throws = 0")
CODE (L"#repeat")
CODE (L"   eyes = randomInteger (1, 6) + randomInteger (1, 6)")
CODE (L"   throws = throws + 1")
CODE (L"#until eyes = 12")
CODE (L"#echo It took me 'throws' trials to throw 12 with two dice.")
NORMAL (L"The statements in the #repeat/#until loop are executed at least once.")
ENTRY (L"\"While\" loops")
TAG (L"#while %expression")
DEFINITION (L"if the expression evaluates to zero or %false, the execution of the script jumps "
	"after the matching #endwhile.")
TAG (L"#endwhile")
DEFINITION (L"execution jumps back to the matching preceding #while line, which is then evaluated again.")
NORMAL (L"The following script forces the number %x into the range [0; 2\\pi):")
CODE (L"#while x < 0")
CODE (L"   x = x + 2 * pi")
CODE (L"#endwhile")
CODE (L"#while x >= 2 * pi")
CODE (L"   x = x - 2 * pi")
CODE (L"#endwhile")
NORMAL (L"If the expression evaluates to zero or %false to begin with, the statements between #while and #endwhile "
	"are not executed even once.")
MAN_END

MAN_BEGIN (L"Scripting 5.5. Procedures", L"ppgb", 20070225)
NORMAL (L"In a Praat script, you can define and call %procedures (subroutines).")
TAG (L"#call %procedureName [%argument1 [%argument2 [...]]]")
DEFINITION (L"the execution of the script jumps to the line after the matching #procedure line, "
	"which can be anywhere in the script.")
TAG (L"#procedure %procedureName [%parameter1 [%parameter2 [...]]]")
DEFINITION (L"introduces a procedure definition (when the execution of the script happens to arrive here, "
	"it jumps after the matching #endproc, i.e., the statements in the procedure are ignored).")
TAG (L"#endproc")
DEFINITION (L"the execution of the script jumps to the line after the #call line that invoked this procedure.")
NORMAL (L"The following script plays three notes:")
CODE (L"#call play_note 440")
CODE (L"#call play_note 400")
CODE (L"#procedure play_note frequency")
CODE (L"   Create Sound from formula... note Mono 0 0.3 44100 0.9 * sin (2*pi*'frequency'*x)")
CODE (L"   Play")
CODE (L"   Remove")
CODE (L"#endproc")
CODE (L"#call play_note 500")
NORMAL (L"The variable %frequency is a normal variable, global to the script. "
	"The procedure uses the same name space as the rest of the script, so beware of possible conflicts.")
NORMAL (L"For arguments that contain spaces, you use double quotes, except for the last argument, "
	"which is the rest of the line:")
CODE (L"#call Conjugate be \"I am\" \"you are\" she is")
CODE (L"#procedure Conjugate verb\\$  first\\$  second\\$  third\\$ ")
CODE (L"   #echo Conjugation of 'to 'verb\\$ '':")
CODE (L"   #printline 1sg 'first\\$ '")
CODE (L"   #printline 2sg 'second\\$ '")
CODE (L"   #printline 3sg 'third\\$ '")
CODE (L"#endproc")
NORMAL (L"Arguments (except for the last) that contain double quotes should also be put between double quotes, and the "
	"double quotes should be doubled:")
CODE (L"#procedure texts top\\$  bottom\\$ ")
CODE (L"   Text top... yes 'top\\$ '")
CODE (L"   Text bottom... yes 'bottom\\$ '")
CODE (L"#endproc")
CODE (L"#call texts \\\" \\\" \\\" hello\\\" \\\"  at the top\\\"  \\\" goodbye\\\"  at the bottom")
MAN_END

MAN_BEGIN (L"Scripting 5.6. Arrays", L"ppgb", 20020624)
NORMAL (L"Quote substitution allows you to simulate arrays of variables:")
CODE (L"#for i #from 1 #to 5")
CODE (L"   square'i' = i * i")
CODE (L"#endfor")
NORMAL (L"After this, the variables %square1, %square2, %square3, %square4, and %square5 contain "
	"the values 1, 4, 9, 16, and 25, respectively.")
NORMAL (L"You can use any number of variables in a script, but you can also use Matrix or Sound objects for arrays.")
NORMAL (L"You can substitute variables with the usual single quotes, as in $$'square3'$. "
	"If the index is also a variable, however, you may need a dummy variable:")
CODE (L"#echo Some squares:")
CODE (L"#for i #from 1 #to 5")
CODE (L"   #hop = square'i'")
CODE (L"   #printline The square of 'i' is 'hop'")
CODE (L"#endfor")
NORMAL (L"The reason for this is that the following line would not work, because of the required "
	"double substitution:")
CODE (L"#print The square of 'i' is 'square'i''")
MAN_END

MAN_BEGIN (L"Scripting 5.7. Including other scripts", L"ppgb", 20080530)
INTRO (L"You can include other scripts within your script:")
CODE (L"a = 5")
CODE (L"include square.praat")
CODE (L"echo 'a'")
NORMAL (L"The Info window will show the result 25 if the file square.praat is as follows:")
CODE (L"a = a * a")
NORMAL (L"The inclusion is done before any other part of the script is considered, so you can use the #form statement "
	"and all variables in it. Usually, however, you will put some procedure definitions in the include file, that is "
	"what it seems to be most useful for. Watch out, however, for using variable names in the include file: "
	"the example above shows that there is no such thing as a separate name space.")
NORMAL (L"Since including other scripts is the first thing Praat will do when considering a script, "
	"you cannot use variable substitution. For instance, the following will not work:")
CODE (L"scriptName\\$  = \"myscript.praat\"")
CODE (L"\\# This will *not* work:")
CODE (L"include 'scriptName\\$ '")
CODE (L"\\# That did *not* work!!!")
NORMAL (L"You can use full or relative file names. For instance, the file square.praat is expected to be in the same "
	"directory as the script that says %%include square.praat%. If you use the ScriptEditor, you will first have to save "
	"the script that you are editing before any relative file names become meaningful (this is the same as with other "
	"uses of relative file names in scripts).")
NORMAL (L"You can %nest include files, i.e., included scripts can include other scripts. However, relative file names "
	"are always evaluated relative to the directory of the outermost script.")
NORMAL (L"The #include statement can only be at the start of a line: you cannot put any spaces in front of it.")
MAN_END

MAN_BEGIN (L"Scripting 5.8. Quitting", L"ppgb", 20040414)
NORMAL (L"Usually, the execution of your script ends when the interpreter has executed the last line "
	"that is not within a procedure definition. However, you can also explicitly stop the script:")
TAG (L"#exit")
DEFINITION (L"stops the execution of the script in the normal way, i.e. without any messages to the user. "
	"Any settings window is removed from the screen.")
TAG (L"#exit %%error-message%")
DEFINITION (L"stops the execution of the script while sending an error message to the user. "
	"Any settings window will stay on the screen.")
NORMAL (L"For an example, see @@Scripting 6.8. Messages to the user@.")
MAN_END

MAN_BEGIN (L"Scripting 6. Communication outside the script", L"ppgb", 20080106)
LIST_ITEM (L"@@Scripting 6.1. Arguments to the script@ (form/endform, execute)")
LIST_ITEM (L"@@Scripting 6.2. Writing to the Info window@ (echo, print, printtab, printline)")
LIST_ITEM (L"@@Scripting 6.3. Query commands@ (Get, Count)")
LIST_ITEM (L"@@Scripting 6.4. Files@ (fileReadable, <, >, >>, filedelete, fileappend)")
LIST_ITEM (L"@@Scripting 6.5. Calling system commands@ (system, environment\\$ , stopwatch)")
LIST_ITEM (L"@@Scripting 6.6. Controlling the user@ (pause)")
LIST_ITEM (L"@@Scripting 6.7. Sending a message to another program@ (sendsocket)")
LIST_ITEM (L"@@Scripting 6.8. Messages to the user@ (exit, assert, nowarn, nocheck)")
LIST_ITEM (L"@@Scripting 6.9. Calling from the command line")
MAN_END

MAN_BEGIN (L"Scripting 6.1. Arguments to the script", L"ppgb", 20070225)
NORMAL (L"You can cause a Praat script to prompt for arguments. The file $$playSine.praat$ may contain the following:")
CODE (L"#form Play a sine wave")
CODE (L"   #positive Sine_frequency_(Hz) 377")
CODE (L"   #positive Gain_(0..1) 0.3 (= not too loud)")
CODE (L"#endform")
CODE (L"Create Sound from formula... sine'sine_frequency' Mono 0 1 44100   'gain' * sin (2*pi*'sine_frequency'*x)")
CODE (L"Play")
CODE (L"Remove")
NORMAL (L"When running this script, the interpreter puts a settings window (%form) on your screen, "
	"entitled \"Play a sine wave\", "
	"with two fields, titled \"Sine frequency (Hz)\" and \"Gain\", that have been provided "
	"with the standard values \"377\" and \"0.3 (= not too loud)\", which you can change before clicking #OK.")
NORMAL (L"As you see, the underscores have been replaced with spaces: that looks better in the form. "
	"Inside the script, the field names can be accessed as variables: these do contain the underscores, "
	"since they must not contain spaces, but the parentheses (Hz) have been chopped off. Note that the first "
	"letter of these variables is converted to lower case, so that you can assign to them in your script.")
NORMAL (L"Inside the script, the value \"0.3 (= not too loud)\" will be known as \"0.3\", "
	"because this is a numeric field.")
NORMAL (L"You can use the following field types in your forms:")
TAG (L"#real %variable %initialValue")
DEFINITION (L"for real numbers.")
TAG (L"#positive %variable %initialValue")
DEFINITION (L"for positive real numbers: the form issues an error message if the number "
	"that you enter is negative or zero; further on in the script, the number may take on any value.")
TAG (L"#integer %variable %initialValue")
DEFINITION (L"for whole numbers: the form reads the number as an integer; "
	"further on in the script, the number may take on any real value.")
TAG (L"#natural %variable %initialValue")
DEFINITION (L"for positive whole numbers: the form issues an error message if the number "
	"that you enter is negative or zero; further on in the script, the number may take on any real value.")
TAG (L"#word %variable %initialValue")
DEFINITION (L"for a string without spaces: the form only reads up to the first space (\"oh yes\" becomes \"oh\"); "
	"further on in the script, the string may contain spaces.")
TAG (L"#sentence %variable %initialValue")
DEFINITION (L"for any short string.")
TAG (L"#text %variable %initialValue")
DEFINITION (L"for any possibly long string (the variable name will not be shown in the form).")
TAG (L"#boolean %variable %initialValue")
DEFINITION (L"a check box will be shown; the value is 0 if off, 1 if on.")
TAG (L"#choice %variable %initialValue")
DEFINITION (L"a radio box will be shown; the value is 1 or higher. This is followed by a series of:")
TAG (L"#button %text")
DEFINITION (L"a button in a radio box.")
TAG (L"#comment %text")
DEFINITION (L"a line with any text.")
NORMAL (L"Inside the script, strings are known as string variables, numbers as numeric variables:")
CODE (L"#form Sink it")
CODE (L"   #sentence Name_of_the_ship Titanic")
CODE (L"   #real Distance_to_the_iceberg_(m) 500.0")
CODE (L"   #natural Number_of_people 1800")
CODE (L"   #natural Number_of_boats 10")
CODE (L"#endform")
NORMAL (L"In this script, the variables are known as %%name_of_the_ship\\$ %, %distance_to_the_iceberg, "
	"%number_of_people, and %number_of_boats.")
NORMAL (L"The variable associated with a radio box will get a numeric as well as a string value:")
CODE (L"#form Fill attributes")
CODE (L"   #comment Choose any colour and texture for your paintings")
CODE (L"   #choice Colour: 5")
CODE (L"      #button Dark red")
CODE (L"      #button Sea green")
CODE (L"      #button Navy blue")
CODE (L"      #button Canary yellow")
CODE (L"      #button Black")
CODE (L"      #button White")
CODE (L"   #choice Texture: 1")
CODE (L"      #button Smooth")
CODE (L"      #button Rough")
CODE (L"      #button With holes")
CODE (L"#endform")
CODE (L"#echo You chose the colour 'colour\\$ ' and texture 'texture\\$ '.")
NORMAL (L"This shows two radio boxes. In the Colour box, the fifth button (Black) is the standard value here. "
	"If you click on \"Navy blue\" and then #%OK, the variable %colour will have the value \"3\", "
	"and the variable %%colour\\$ % will have the value \"Navy blue\". "
	"Note that the trailing colon is chopped off, and that the button and comment texts may contain spaces. "
	"So you can test the value of the Colour box in either of the following ways:")
CODE (L"if colour = 4")
NORMAL (L"or")
CODE (L"if colour\\$  = \"Canary yellow\"")
NORMAL (L"The field types #optionmenu and #option are completely analogous to #choice and #button, "
	"but use up much less space on the screen:")
CODE (L"#form Fill attributes")
CODE (L"   #comment Choose any colour and texture for your paintings")
CODE (L"   #optionmenu Colour: 5")
CODE (L"      #option Dark red")
CODE (L"      #option Sea green")
CODE (L"      #option Navy blue")
CODE (L"      #option Canary yellow")
CODE (L"      #option Black")
CODE (L"      #option White")
CODE (L"   #optionmenu Texture: 1")
CODE (L"      #option Smooth")
CODE (L"      #option Rough")
CODE (L"      #option With holes")
CODE (L"#endform")
CODE (L"#echo You chose the colour 'colour\\$ ' and texture 'texture\\$ '.")
NORMAL (L"You can combine two short fields into one by using %left and %right:")
CODE (L"#form Get duration")
CODE (L"   #natural left_Year_range 1940")
CODE (L"   #natural right_Year_range 1945")
CODE (L"#endform")
CODE (L"duration = right_Year_range - left_Year_range")
CODE (L"#echo The duration is 'duration' years.")
NORMAL (L"The interpreter will only show the single text \"Year range\", followed by two small text fields.")
ENTRY (L"Calling a script from another script")
NORMAL (L"Scripts can be nested: the file %%doremi.praat% may contain the following:")
CODE (L"#execute playSine.praat 550 0.9")
CODE (L"#execute playSine.praat 615 0.9")
CODE (L"#execute playSine.praat 687 0.9")
NORMAL (L"With the #execute command, Praat will not display a form window, but simply execute the script "
	"with the two arguments that you supply on the same line (e.g. 550 and 0.9).")
NORMAL (L"Arguments (except for the last) that contain spaces must be put between double quotes, "
	"and values for #choice must be passed as strings:")
CODE (L"#execute \"fill attributes.praat\" \"Navy blue\" With holes")
NORMAL (L"You can pass values for #boolean either as \"yes\" and \"no\" or 1 and 0.")
MAN_END

MAN_BEGIN (L"Scripting 6.2. Writing to the Info window", L"ppgb", 20070225)
NORMAL (L"With the @Info button and several commands in the #Query menus, "
	"you write to the @@Info window@. If your program is run from batch (on Unix or Windows), "
	"the text goes to %stdout.")
NORMAL (L"The following commands allow you to write to the Info window from a script only:")
TAG (L"#echo %text")
DEFINITION (L"clears the Info window and writes some text to it:")
CODE (L"   #echo Starting simulation...")
TAG (L"#clearinfo")
DEFINITION (L"clears the Info window.")
TAG (L"#print %text")
DEFINITION (L"appends some text to the Info window, without clearing it and "
	"without going to a new line.")
TAG (L"#printtab")
DEFINITION (L"appends a %tab character to the Info window. This allows you to create "
	"table files that can be read by some spreadsheet programs.")
TAG (L"#printline [%text]")
DEFINITION (L"causes the following text in the Info window to begin at a new line. "
	"You can add text, just like with #print.")
NORMAL (L"The following script builds a table with statistics about a pitch contour:")
CODE (L"#clearinfo")
CODE (L"#printline  Minimum   Maximum")
CODE (L"Create Sound from formula... sin Mono 0 0.1 44100 sin(2*pi*377*x)")
CODE (L"To Pitch... 0.01 75 600")
CODE (L"minimum = Get minimum... 0 0 Hertz Parabolic")
CODE (L"#print 'minimum'")
CODE (L"#printtab")
CODE (L"maximum = Get maximum... Hertz")
CODE (L"#print 'maximum'")
CODE (L"#printline")
NORMAL (L"You could combine the last four print statements into:")
CODE (L"#printline 'minimum''tab\\$ ''maximum'")
NORMAL (L"or:")
CODE (L"#print 'minimum''tab\\$ ''maximum''newline\\$ '")
MAN_END

MAN_BEGIN (L"Scripting 6.3. Query commands", L"ppgb", 19990108)
NORMAL (L"If you click the \"Get mean...\" command for a Pitch object, "
	"the Info window will contain a text like \"150 Hz\" as a result. In a script, you would rather "
	"have this result in a variable instead of in the Info window. The solution is simple:")
CODE (L"mean = Get mean... 0 0 Hertz Parabolic")
NORMAL (L"The numeric variable \"mean\" now contains the number 150. When assigning to a numeric variable, "
	"the interpreter converts the part of the text before the first space into a number.")
NORMAL (L"You can also assign to string variables:")
CODE (L"mean\\$  = Get mean... 0 0 Hertz Parabolic")
NORMAL (L"The string variable \"mean\\$ \" now contains the entire string \"150 Hz\".")
NORMAL (L"This works for every command that would otherwise write into the Info window.")
MAN_END

MAN_BEGIN (L"Scripting 6.4. Files", L"ppgb", 20010821)
INTRO (L"You can read from and write to text files from a Praat script.")
ENTRY (L"Reading a file")
NORMAL (L"You can check the availability of a file for reading with the function")
CODE (L"#fileReadable (fileName\\$ )")
NORMAL (L"which returns #true if the file exists and can be read, and #false otherwise.")
NORMAL (L"To read the contents of an existing text file into a string variable, you use")
CODE (L"text\\$  ##<# %fileName")
NORMAL (L"where $$text\\$ $ is any string variable and $$%fileName$ is an unquoted string. "
	"If the file does not exist, the script terminates with an error message.")
ENTRY (L"Example: reading a settings file")
NORMAL (L"Suppose that the file ##height.inf# may contain an appropriate value for a numeric variable "
	"called $height, which we need to use in our script. We would like to read it with")
CODE (L"height\\$  < height.inf")
CODE (L"height = 'height\\$ '")
NORMAL (L"However, this script will fail if the file ##height.inf# does not exist. To guard "
	"against this situation, we could check the existence of the file, and supply a default "
	"value in case the file does not exist:")
CODE (L"fileName\\$  = \"height.inf\"")
CODE (L"if fileReadable (fileName\\$ )")
CODE (L"   height\\$  < 'fileName\\$ '")
CODE (L"   height = 'height\\$ '")
CODE (L"else")
CODE (L"   height = 180")
CODE (L"endif")
ENTRY (L"Writing a file")
NORMAL (L"To write the contents of an existing string into a new text file, you use")
CODE (L"text\\$  ##># %fileName")
NORMAL (L"where $$text\\$ $ is any string variable and $$%fileName$ is an unquoted string. "
	"If the file cannot be created, the script terminates with an error message.")
NORMAL (L"To append the contents of an existing string at the end of an existing text file, you use")
CODE (L"text\\$  ##>># %fileName")
NORMAL (L"If the file does not yet exist, it is created first.")
NORMAL (L"You can delete an existing file with")
CODE (L"#filedelete %fileName")
NORMAL (L"If the file does not exist, #filedelete does nothing.")
NORMAL (L"The simplest way to append text to a file is by using #fileappend:")
CODE (L"#fileappend out.txt Hello world!")
ENTRY (L"Example: writing a table of squares")
NORMAL (L"Suppose that we want to create a file with the following text:")
CODE (L"The square of 1 is 1")
CODE (L"The square of 2 is 4")
CODE (L"The square of 3 is 9")
CODE (L"...")
CODE (L"The square of 100 is 10000")
NORMAL (L"We can do this by collecting each line in a variable:")
CODE (L"filedelete squares.txt")
CODE (L"for i to 100")
CODE (L"   square = i * i")
CODE (L"   fileappend squares.txt The square of 'i' is 'square''newline\\$ '")
CODE (L"endfor")
NORMAL (L"Note that we delete the file before appending to it, "
	"in order that we do not append to an already existing file.")
NORMAL (L"If you put the name of the file into a variable, make sure to surround it "
	"with double quotes when using #fileappend, since the file name may contain spaces "
	"and is not at the end of the line:")
CODE (L"name\\$  = \"Hard disk:Desktop Folder:squares.text\"")
CODE (L"filedelete 'name\\$ '")
CODE (L"for i to 100")
CODE1 (L"square = i * i")
CODE1 (L"fileappend \"'name\\$ '\" The square of 'i' is 'square''newline\\$ '")
CODE (L"endfor")
NORMAL (L"Finally, you can append the contents of the Info window to a file with")
CODE (L"#fappendinfo %fileName")
ENTRY (L"Directory listings")
NORMAL (L"To get the names of the files if a certain type in a certain directory, "
	"use @@Create Strings as file list...@.")
MAN_END

MAN_BEGIN (L"Scripting 6.5. Calling system commands", L"ppgb", 20080106)
INTRO (L"From a Praat script you can call system commands. "
	"These are the same commands that you would normally type into a terminal window or into the Window command line prompt.")
TAG (L"#system %command")
DEFINITION (L"executes a system command.")
NORMAL (L"Some system commands are identical on all platforms (Macintosh, Windows, Unix):")
CODE (L"#system mkdir sounds")
NORMAL (L"which creates a new directory #sounds in the directory of the script. Some other system commands "
	"are different on different platforms. For instance, to throw away all WAV files in the script's directory, "
	"you would write")
CODE (L"#system del *.wav")
NORMAL (L"on Windows, but")
CODE (L"#system rm *.wav")
NORMAL (L"on Macintosh and Unix.")
NORMAL (L"The script will stop running if a system command returns an error. For instance,")
CODE (L"#system mkdir sounds")
NORMAL (L"will stop the script if the directory #sounds already exists. "
	"In order to prevent this, you can tell Praat to ignore the return value of the system command:")
TAG (L"#system_nocheck %command")
DEFINITION (L"executes a system command, ignoring any errors.")
NORMAL (L"Thus, to make sure that the directory #sounds exists, you would write")
CODE (L"#system_nocheck mkdir sounds")
TAG (L"##environment\\$  (#%%symbol-string%#)")
DEFINITION (L"returns the value of an environment variable, e.g.")
CODE1 (L"homeDirectory\\$  = ##environment\\$ # (\"HOME\")")
TAG (L"##stopwatch")
DEFINITION (L"returns the time that has elapsed since the previous #stopwatch.")
NORMAL (L"Here is a Praat script that measures how long it takes to do a million assignments:")
CODE (L"stopwatch")
CODE (L"for i to 1000000")
CODE1 (L"a = 1.23456789e123")
CODE (L"endfor")
CODE (L"time = stopwatch")
CODE (L"echo 'a' 'time:3'")
MAN_END

MAN_BEGIN (L"Scripting 6.6. Controlling the user", L"ppgb", 20040414)
INTRO (L"You can temporarily halt a Praat script:")
TAG (L"#pause %text")
DEFINITION (L"suspends execution of the script, and allows the user to interrupt it. "
	"A message window will appear with the %text and the buttons Continue and Stop:")
CODE (L"   #pause The next file will be beerbeet.TextGrid")
MAN_END

MAN_BEGIN (L"Scripting 6.7. Sending a message to another program", L"ppgb", 20021218)
NORMAL (L"To send messages to running programs that use the Praat shell, "
	"use $sendpraat (see @@Scripting 8. Controlling Praat from another program@).")
NORMAL (L"To send a message to another running program that listens to a socket, "
	"you can use the $sendsocket directive. This works on Unix and Windows only.")
ENTRY (L"Example")
NORMAL (L"Suppose we are in the Praat-shell program #Praat, which is a system for doing phonetics by computer. "
	"From this program, we can send a message to the %%non%-Praat-shell program #MovieEdit, "
	"which does know how to display a sound file:")
CODE (L"Write to file... hallo.wav")
CODE (L"sendsocket fonsg19.hum.uva.nl:6667 display hallo.wav")
NORMAL (L"In this example, $$fonsg19.hum.uva.nl$ is the computer on which MovieEdit is running; "
	"you can specify any valid Internet address instead, as long as that computer allows you to send messages to it. "
	"If MovieEdit is running on the same computer as Praat, you can specify $localhost instead of the full Internet address.")
NORMAL (L"The number 6667 is the port number on which MovieEdit is listening. Other programs will use different port numbers.")
MAN_END

MAN_BEGIN (L"Scripting 6.8. Messages to the user", L"ppgb", 20041027)
NORMAL (L"If the user makes a mistake (e.g. types conflicting settings into your form window), "
	"you can use the #exit directive (@@Scripting 5.8. Quitting|\\SS5.7@) "
	"to stop the execution of the script with an error message:")
CODE (L"form My analysis")
CODE1 (L"real Starting_time_(s) 0.0")
CODE1 (L"real Finishing_time_(s) 1.0")
CODE (L"endform")
CODE (L"if finishing_time <= starting_time")
CODE1 (L"#exit The finishing time should exceed 'starting_time' seconds.")
CODE (L"endif")
CODE (L"\\#  Proceed with the analysis...")
NORMAL (L"For things that should not normally go wrong, you can use the #assert directive:")
CODE (L"power = Get power")
CODE (L"assert power > 0")
NORMAL (L"This is the same as:")
CODE (L"if (power > 0) = undefined")
CODE1 (L"exit Assertion failed in line xx (undefined): power > 0")
CODE (L"elsif not (power > 0)")
CODE1 (L"exit Assertion failed in line xx (false): power > 0")
CODE (L"endif")
NORMAL (L"You can prevent Praat from issuing warning messages:")
CODE (L"nowarn Write to WAV file... hello.wav")
NORMAL (L"This prevents warning messages about clipped samples, for instance.")
NORMAL (L"You can also prevent Praat from showing a progress window:")
CODE (L"noprogress To Pitch... 0 75 500")
NORMAL (L"This prevents the progress window from popping up during lengthy operations. "
	"Use this only if you want to prevent the user from stopping the execution of the script.")
NORMAL (L"Finally, you can make Praat ignore error messages:")
CODE (L"nocheck Remove")
NORMAL (L"This would cause the script to continue even if there is nothing to remove.")
MAN_END

MAN_BEGIN (L"Scripting 6.9. Calling from the command line", L"ppgb", 20040414)
INTRO (L"On most computers, you can call a Praat script from the command line.")
ENTRY (L"Command lines on Unix and MacOS X")
NORMAL (L"On Unix or MacOS X, you call Praat scripts from the command line like this:")
CODE (L"> /people/mietta/praat doit.praat 50 hallo")
NORMAL (L"or")
CODE (L"> /Applications/Praat.app/Contents/MacOS/Praat doit.praat 50 hallo")
NORMAL (L"This opens P\\s{RAAT}, runs the script ##doit.praat# with arguments \"50\" and \"hallo\", "
	"and closes P\\s{RAAT}.")
NORMAL (L"You also have the possibility of running the program interactively from the command line:")
CODE (L"> /people/mietta/praat -")
NORMAL (L"You can then type in any of the fixed and dynamic commands, and commands that handle object selection, "
	"like #select. This method also works in pipes:")
CODE (L"> echo \"Statistics...\" | /people/mietta/praat -")
ENTRY (L"Command lines on Windows")
NORMAL (L"On Windows, you call Praat scripts from the command line like this:")
CODE (L"e:\\bspraatcon.exe e:\\bsdoit.praat 50 hallo")
NORMAL (L"Note that you use ##praatcon.exe# instead of ##praat.exe#. The script will write to the console output, and its output "
	"can be used in pipes.")
ENTRY (L"How to get arguments into the script")
NORMAL (L"In the above example, the script ##doit.praat# requires two arguments. In the script ##doit.praat#, "
	"you use #form and #endform to receive these arguments. See @@Scripting 6.1. Arguments to the script@. "
	"As with the #execute command, Praat will not present a form window, but simply execute the script "
	"with the arguments given on the command line. The example given in @@Scripting 6.1. Arguments to the script@ "
	"will be called in the following way:")
CODE (L"> /people/mietta/praat playSine.praat 550 0.9")
NORMAL (L"or")
CODE (L"e:\\bspraatcon.exe playSine.praat 550 0.9")
MAN_END

MAN_BEGIN (L"Scripting 7. Scripting the editors", L"ppgb", 20040222)
NORMAL (L"With a Praat script, you can automatize your work in the editors.")
NORMAL (L"#Warning: if the purpose of your script is to get information about "
	"analyses (pitch, formants, intensity, spectrogram) from the Sound, "
	"we do %not advise to script the Sound editor window. "
	"It is much simpler, faster, and more reproducible to create the analyses "
	"with the commands of the @@dynamic menu@, then use the Query commands of the dynamic menu "
	"to extract information from the analyses. This also applies if you want to use a TextGrid "
	"to determine the times at which you want to query the analyses. "
	"See @@Scripting examples@.")
LIST_ITEM1 (L"@@Scripting 7.1. Scripting an editor from a shell script@ (editor/endeditor)")
LIST_ITEM1 (L"@@Scripting 7.2. Scripting an editor from within@")
MAN_END

MAN_BEGIN (L"Scripting 7.1. Scripting an editor from a shell script", L"ppgb", 20010606)
NORMAL (L"From a Praat shell script, you can switch to an editor and back again:")
CODE (L"sound\\$  = \"hallo\"")
CODE (L"start = 0.3")
CODE (L"finish = 0.7")
CODE (L"Read from file... 'sound\\$ '.aifc")
CODE (L"Edit")
CODE (L"#editor Sound 'sound\\$ '")
CODE (L"   Zoom... start finish")
CODE (L"#endeditor")
CODE (L"Play")
NORMAL (L"This script reads a sound file from disk, pops up an editor for the resulting object, "
	"makes this editor zoom in on the part between 0.3 and 0.7 seconds, "
	"and returns to the Praat shell to play the entire sound.")
MAN_END

MAN_BEGIN (L"Scripting 7.2. Scripting an editor from within", L"ppgb", 20050822)
NORMAL (L"This section will show how you can permanently extend the functionality of an editor.")
NORMAL (L"As an example, consider the following problem: you want to see a graphic representation "
	"of the spectrum of the sound around the cursor position in the SoundEditor. To achieve this, "
	"follow these steps:")
LIST_ITEM (L"1. Create a Sound.")
LIST_ITEM (L"2. View it in a SoundEditor by clicking @Edit.")
LIST_ITEM (L"3. Choose ##New editor script# from the @@File menu@ in the SoundEditor. The resulting @ScriptEditor "
	"will have a name like \"untitled script [Sound hallo]\".")
LIST_ITEM (L"4. Type the following lines into the ScriptEditor:")
CODE2 (L"cursor = Get cursor")
CODE2 (L"Select... cursor-0.02 cursor+0.02")
CODE2 (L"Extract windowed selection... slice Kaiser2 2 no")
CODE1 (L"#endeditor")
CODE1 (L"To Spectrum (fft)")
CODE1 (L"Edit")
NORMAL (L"If you choose Run from the Run menu in the ScriptEditor, a region of 40 milliseconds around the "
	"current cursor position in the SoundEditor will become selected. This piece will be copied to the list of objects, "
	"after applying a double Kaiser window (total length 80 ms). Thus, a Sound named \"slice\" will appear in the list. "
	"Subsequently, a Spectrum object also called \"slice\" will appear in the list, and a SpectrumEditor titled "
	"\"Spectrum slice\" will finally appear on your screen.")
LIST_ITEM (L"5. Save the script to disk, e.g. as /us/miep/spectrum.praat. The title of the ScriptEditor will change accordingly.")
LIST_ITEM (L"6. Since you will want this script to be available in all future SoundEditors, you choose ##Add to menu...# from the File menu. "
	"For the %Window, you specify \"SoundEditor\" (this is preset). For the %Menu, you may want to choose \"Spec.\" "
	"instead of the preset value (\"File\"). For the name of the %Command, you type something like \"Show spectrum at cursor\" "
	"(instead of \"Do it...\"). Then you click OK.")
NORMAL (L"The command will be visible in every SoundEditor that you create from now on. "
	"To see this, close the one visible SoundEditor, select the original Sound, choose Edit again, and inspect the \"Spec.\" menu. "
	"You can now view the spectrum around the cursor just by choosing this menu command.")
NORMAL (L"After you leave Praat and start it again, the command will continue to appear in the SoundEditor. "
	"If you don't like the command any longer, you can remove it with the @ButtonEditor, which you can start "
	"by choosing #Buttons from the Preferences submenu of the @@Praat menu@.")
ENTRY (L"Improving your script")
NORMAL (L"The above spectrum-viewing example has a number of disadvantages. It clutters the object list with a number "
	"of indiscriminable Sounds and Spectra called \"slice\", and the spectrum is shown up to the Nyquist frequency "
	"while we may just be interested in the lower 5000 Hz. Furthermore, the original selection in the SoundEditor is lost.")
NORMAL (L"To improve the script, we open it again with ##Open editor script...# from the File menu in the SoundEditor. After every change, "
	"we can run it with Run from the Run menu again; alternatively, we could save it (with Save from the File menu) and choose our new "
	"\"Show spectrum at cursor\" button (this button will always run the version on disk, never the one viewed in a ScriptEditor).")
NORMAL (L"To zoom in on the first 5000 Hz, we add the following code at the end of our script:")
CODE (L"#editor Spectrum slice")
CODE1 (L"Zoom... 0 5000")
NORMAL (L"To get rid of the \"Sound slice\", we can add:")
CODE (L"#endeditor")
CODE (L"select Sound slice")
CODE (L"Remove")
NORMAL (L"Note that #endeditor is needed to change from the environment of a SpectrumEditor to the environment of the object & picture windows.")
NORMAL (L"If you now choose the \"Show spectrum at cursor\" button for several cursor positions, you will notice that all those editors have the same name. "
	"To remedy the ambiguity of the line $$#editor Spectrum slice$, we give each slice a better name. For example, if the cursor was at "
	"635 milliseconds, the slice could be named \"635ms\". We can achieve this by changing the extraction in the following way:")
CODE (L"milliseconds = round (cursor*1000)")
CODE (L"Extract windowed selection... 'milliseconds'ms Kaiser2 2 no")
NORMAL (L"The names of the Sound and Spectrum objects will now have more chance of being unique. Two lines will have to be edited trivially.")
NORMAL (L"Finally, we will reset the selection to the original. At the top of the script, we add two lines to remember the positions of the selection markers:")
CODE (L"begin = Get begin of selection")
CODE (L"end = Get end of selection")
NORMAL (L"At the bottom, we reset the selection:")
CODE (L"#editor")
CODE1 (L"Select... begin end")
NORMAL (L"Note that the #editor directive if not followed by the name of an editor, returns the script to the original environment.")
NORMAL (L"The complete script is:")
CODE1 (L"begin = Get begin of selection")
CODE1 (L"end = Get end of selection")
CODE1 (L"cursor = Get cursor")
CODE1 (L"Select... cursor-0.02 cursor+0.02")
CODE1 (L"\\#  Create a name. E.g. \"670ms\" means at 670 milliseconds.")
CODE1 (L"milliseconds = round (cursor*1000)")
CODE1 (L"Extract windowed selection... 'milliseconds'ms Kaiser2 2 no")
CODE (L"#endeditor")
CODE (L"To Spectrum (fft)")
CODE (L"Edit")
CODE (L"#editor Spectrum 'milliseconds'ms")
CODE1 (L"Zoom... 0 5000")
CODE (L"#endeditor")
CODE (L"select Sound 'milliseconds'ms")
CODE (L"Remove")
CODE (L"#editor")
CODE1 (L"Select... begin end")
NORMAL (L"This script is useful as it stands. It is good enough for safe use. For instance, if the created Sound object has the same name "
	"as an already existing Sound object, it will be the newly created Sound object that will be removed in the $Remove line, "
	"because #select always selects the most recently created object in case of ambiguity.")
MAN_END

MAN_BEGIN (L"sendpraat", L"ppgb", 20000927)
NORMAL (L"See @@Scripting 8. Controlling Praat from another program@.")
MAN_END

MAN_BEGIN (L"Scripting 8. Controlling Praat from another program", L"ppgb", 20021218)
LIST_ITEM (L"@@Scripting 8.1. The sendpraat subroutine")
LIST_ITEM (L"@@Scripting 8.2. The sendpraat program")
LIST_ITEM (L"@@Scripting 8.3. The sendpraat directive")
MAN_END

MAN_BEGIN (L"Scripting 8.1. The sendpraat subroutine", L"ppgb", 20050822)
INTRO (L"A subroutine for sending messages to a %running P\\s{RAAT}. "
	"Also a Unix, MacOS, or DOS console program with the same purpose.")
ENTRY (L"Syntax")
LIST_ITEM (L"##sendpraat (void *#%display##, const char *#%program##, long #%timeOut##, char *#%text##);")
ENTRY (L"Arguments")
TAG (L"%display")
DEFINITION (L"the display pointer if the subroutine is called from a running X program; "
	"if NULL, sendpraat will open the display by itself. On Windows and Macintosh, "
	"this argument is ignored.")
TAG (L"%program")
DEFINITION (L"the name of a running program that uses the Praat shell, e.g. \"Praat\" or \"ALS\". "
	"The first letter may be specified as lower or upper case; it will be converted to lower case for Unix "
	"and to upper case for Macintosh and Windows.")
TAG (L"%message")
DEFINITION (L"a sequence of Praat shell lines (commands and directives).")
TAG (L"%timeOut (Unix and Macintosh only)")
DEFINITION (L"the number of seconds that sendpraat will wait for an answer "
	"before writing an error message. A %timeOut of 0 means that "
	"the message will be sent asynchronously, i.e., that sendpraat "
	"will return immediately without issuing any error message.")
TAG (L"%text")
DEFINITION (L"the script text to be sent. Sendpraat may alter this text!")
ENTRY (L"Example 1: killing a program")
CODE (L"char message [100], *errorMessage;")
CODE (L"strcpy (message, \"Quit\");")
CODE (L"errorMessage = #sendpraat (NULL, \"praat\", 0, message);")
CODE (L"if (errorMessage != NULL) fprintf (stderr, \"\\% s\", errorMessage);")
NORMAL (L"This causes the program #Praat to quit (gracefully), because #Quit is a fixed "
	"command in one of the menus of that program. "
	"On Unix and Macintosh, sendpraat returns immediately; on Windows, the %timeOut argument is ignored. "
	"The return value %errorMessage is a statically allocated string internal to sendpraat, "
	"and is overwritten by the next call to sendpraat.")
ENTRY (L"Example 2: playing a sound file in reverse")
NORMAL (L"Suppose you have a sound file whose name is in the variable $fileName, "
	"and you want the program #Praat, which can play sounds, "
	"to play this sound backwards.")
CODE (L"char message [1000], *errorMessage;")
CODE (L"sprintf (message, \"Read from file... \\% s\\bsnPlay reverse\\bsnRemove\", fileName);")
CODE (L"errorMessage = #sendpraat (NULL, \"praat\", 1000, message);")
NORMAL (L"This will work because ##Play reverse# is an action command "
	"that becomes available in the dynamic menu when a Sound is selected. "
	"On Unix, sendpraat will allow #Praat at most 1000 seconds to perform this.")
ENTRY (L"Example 3: executing a large script file")
NORMAL (L"Sometimes, it may be unpractical to send a large script directly to #sendpraat. "
	"Fortunately, the receiving program knows the #execute directive:")
CODE (L"char message [100], *errorMessage;")
CODE (L"strcpy (message, \"doAll.praat 20\");")
CODE (L"errorMessage = #sendpraat (NULL, \"praat\", 0, message);")
NORMAL (L"This causes the program #Praat to execute the script ##doAll.praat# with an argument of \"20\".")
ENTRY (L"How to download")
NORMAL (L"You can download the source code of the sendpraat subroutine and program "
	"via ##www.praat.org# or from ##http://www.fon.hum.uva.nl/praat/sendpraat.html#.")
ENTRY (L"See also")
NORMAL (L"To start a program from the command line instead and sending it a message, "
	"you would not use #sendpraat, but instead run the program with a script file as an argument. "
	"See @@Scripting 6.9. Calling from the command line@.")
MAN_END

MAN_BEGIN (L"Scripting 8.2. The sendpraat program", L"ppgb", 20050822)
INTRO (L"A Unix or DOS console program for sending messages to a %running P\\s{RAAT} program.")
ENTRY (L"Syntax")
CODE (L"#sendpraat [%timeOut] %program %message...")
NORMAL (L"For the meaning of the arguments, see @@Scripting 8.1. The sendpraat subroutine|the sendpraat subroutine@.")
ENTRY (L"Example 1: killing a program")
CODE (L"sendpraat 0 praat Quit")
NORMAL (L"Causes the program #Praat to quit (gracefully), because #Quit is a fixed command in one of its menus. "
	"On Unix, #sendpraat returns immediately; on Windows, you leave out the %timeOut argument.")
ENTRY (L"Example 2: playing a sound file in reverse")
CODE (L"sendpraat 1000 praat \"Read from file... hello.wav\" \"Play reverse\" \"Remove\"")
NORMAL (L"This works because ##Play reverse# is an action command "
	"that becomes available in the dynamic menu of the #Praat program when a Sound is selected. "
	"On Unix, sendpraat will allow #Praat at most 1000 seconds to perform this.")
NORMAL (L"Each line is a separate argument. Lines that contain spaces should be put inside double quotes.")
ENTRY (L"Example 3: drawing")
CODE (L"sendpraat als \"for i from 1 to 5\" \"Draw circle... 0.5 0.5 i\" \"endfor\"")
NORMAL (L"This causes the program #Als to draw five concentric circles into the Picture window.")
ENTRY (L"Example 4: executing a large script")
CODE (L"sendpraat praat \"execute doAll.praat 20\"")
NORMAL (L"This causes the program #Praat to execute the script ##doAll.praat# with an argument of \"20\".")
MAN_END

MAN_BEGIN (L"Scripting 8.3. The sendpraat directive", L"ppgb", 20021218)
INTRO (L"Besides being a subroutine (@@Scripting 8.1. The sendpraat subroutine@) "
	"and a program (@@Scripting 8.2. The sendpraat program@), @sendpraat "
	"can also be called from within a Praat script.")
ENTRY (L"Example 1: killing a program")
NORMAL (L"Suppose we are in the Praat-shell program #Als, which is a browser for dictionaries, "
	"and we want to kill the Praat-shell program #Praat, which is a program for phonetics research:")
CODE (L"sendpraat Praat Quit")
ENTRY (L"Example 2: playing a sound")
NORMAL (L"Suppose we are in the Praat-shell program #Als, which is a browser for dictionaries, "
	"and has no idea of what a %sound is. From this program, we can play a sound file "
	"by sending a message to the Praat-shell program #Praat, which does know about sounds:")
CODE (L"fileName\\$  = \"hallo.wav\"")
CODE (L"sendpraat Praat")
CODE (L"...'newline\\$ ' Read from file... 'fileName\\$ '")
CODE (L"...'newline\\$ ' Play")
CODE (L"...'newline\\$ ' Remove")
NORMAL (L"The first $$newline\\$ $ is superfluous, but this format seems to read nicely.")
MAN_END

MAN_BEGIN (L"ScriptEditor", L"ppgb", 20070225)
INTRO (L"An aid to @@scripting@.")
NORMAL (L"The #ScriptEditor is a text editor that allows you to edit, save, and run "
	"any @@Praat script@. You could type such a script from scratch, "
	"but it is easier to use the @@History mechanism@, which automatically records "
	"all your commands and mouse clicks, and which can paste these directly "
	"into a #ScriptEditor.")
NORMAL (L"To add a script as a button to a fixed or dynamic menu, "
	"use @@Add to fixed menu...@ or @@Add to dynamic menu...@ from the @@File menu@.")
ENTRY (L"Example 1")
NORMAL (L"In this example, we create a fixed button that will play a 1-second sine wave with a specified frequency.")
NORMAL (L"First, we create a ScriptEditor by choosing @@New Praat script@ from the @@Praat menu@. "
	"Then, we choose @@Clear history@ from the Edit menu in the ScriptEditor. "
	"We then perform some actions that will create a sine wave, play it, and remove it:")
LIST_ITEM (L"1. Choose ##Create Sound from formula...# from the @@New menu@ and type the formula of a sine wave (i.e. "
	"remove the \"randomGauss\" term).")
LIST_ITEM (L"2. Click #Play in the dynamic menu.")
LIST_ITEM (L"3. Click the fixed #Remove button.")
NORMAL (L"We then choose @@Paste history@ from the Edit menu in the ScriptEditor (or type Command-H). "
	"The text will now contain at least the following lines (delete any other lines):")
CODE (L"Create Sound from formula... sine Mono 0 1 44100 1/2*sin(2*pi*377*x)")
CODE (L"Play")
CODE (L"Remove")
NORMAL (L"We can run this script again by choosing #Run from the #Run menu (or typing Command-R). "
	"However, this always plays a sine with a frequency of 377 Hz, so we will add the variable \"Frequency\" "
	"to the script, which then looks like:")
CODE (L"#form Play a sine wave")
CODE (L"   #positive Frequency")
CODE (L"#endform")
CODE (L"Create Sound from formula... sine'frequency' Mono 0 1 44100 1/2*sin(2*pi*frequency*x)")
CODE (L"Play")
CODE (L"Remove")
NORMAL (L"When we choose #Run, the ScriptEditor will ask us to supply a value for the \"Frequency\" variable. "
	"We can now play 1-second sine waves with any frequency. Note that the name of the temporary Sound "
	"is now \"sine356\" if %Frequency is \"356\": any occurrence of the string \"\'Frequency\'\" is replaced "
	"with the supplied argument.")
NORMAL (L"It is advisable to supply a standard value for each argument in your script. "
	"If the duration should be variable, too, the final script could look like:")
CODE (L"#form Play a sine wave")
CODE (L"   #positive Frequency 440")
CODE (L"   #positive Duration 1")
CODE (L"#endform")
CODE (L"Create Sound from formula... sine'frequency' Mono 0 'Duration' 44100 0.9*sin(2*pi*frequency*x)")
CODE (L"Play")
CODE (L"Remove")
NORMAL (L"When you run this script, the ScriptEditor will ask you to supply values for the two variables, "
	"but the values \"440\" and \"1\" are already visible in the form window, "
	"so that you will get a sensible result if you just click #OK.")
NORMAL (L"If this script is useful to you, you may want to put a button for it in the @@New menu@, "
	"in the ##Sound# submenu:")
LIST_ITEM (L"1. Save the script to a file, with #Save from the #File menu. The file name that you supply, will "
	"be shown in the title bar of the ScriptEditor window.")
LIST_ITEM (L"2. Choose @@Add to fixed menu...@ from the #%File menu. Supply #Objects for the %window, "
	"#New for the %menu, \"Play sine wave...\" for the %command, "
	"##Create Sound from formula...# for %%after command%, and \"1\" for the depth (because it is supposed to be in a submenu); "
	"the %script argument has already been set to the file name that you supplied in step 1.")
LIST_ITEM (L"3. Click #OK and ensure that the button has been added in the @@New menu@. This button will still be there "
	"after you leave the program and enter it again; to remove it from the menu, use the @ButtonEditor.")
ENTRY (L"Example 2")
NORMAL (L"In this example, we will create a shortcut for the usual complex pitch-analysis command.")
NORMAL (L"First, we perform the required actions:")
LIST_ITEM (L"1. Select a Sound object.")
LIST_ITEM (L"2. Click ##To Pitch...# and set the arguments to your personal standard values.")
LIST_ITEM (L"3. Click #OK. A new #Pitch object will appear.")
NORMAL (L"We then paste the history into the ScriptEditor, after which this will contain at least a line like (delete all the other lines):")
CODE (L"To Pitch... 0.01 150 900")
NORMAL (L"You can run this script only after selecting one or more Sound objects.")
NORMAL (L"If this script is useful to you, you may want to put a button for it in the dynamic menu:")
LIST_ITEM (L"1. Save the script to a file, with #Save from the #File menu.")
LIST_ITEM (L"2. Choose @@Add to dynamic menu...@ from the #File menu. Supply \"Sound\" for %class1 "
	"(because the button is supposed to be available only if a Sound is selected), \"0\" for %number1 "
	"(because the command is supposed to work for any number of selected Sound objects), "
	"\"To Pitch (child)\" for the %command, "
	"\"To Spectrum\" for %%after command%, and \"0\" for the depth (because it is not supposed to be in a submenu); "
	"the %script argument has already been set to the file name that you supplied in step 1.")
LIST_ITEM (L"3. Click #OK and ensure that the button is clickable if you select one or more Sound objects. "
	"This button will still be available after you leave the program and enter it again; "
	"to remove it from the dynamic menus, use the @ButtonEditor.")
MAN_END

MAN_BEGIN (L"undefined", L"ppgb", 20040414)
INTRO (L"When you give a query command for a numeric value, Praat sometimes writes the numeric value ##--undefined--# "
	"into the @@Info window@ (two hyphens at both sides of the word). This happens if the value you ask for is not defined, "
	"as in the following examples:")
LIST_ITEM (L"\\bu You select a Sound with a finishing time of 1.0 seconds and ask for the minimum point in the wave form "
	"between 1.5 and 2.0 seconds (with the query command ##Get minimum...#).")
LIST_ITEM (L"\\bu You ask for a pitch value in a voiceless part of the sound (select a #Pitch, "
	"then choose ##Get value at time...#).")
LIST_ITEM (L"\\bu You type into the @Calculator the following formula: 10\\^ 400.")
ENTRY (L"Usage in a script")
NORMAL (L"In a Praat script, this value is simply represented as \"undefined\". You use it to test whether "
	"a query command returned a valid number:")
CODE (L"select Pitch hallo")
CODE (L"meanPitch = Get mean... 0.1 0.2 Hertz Parabolic")
CODE (L"if meanPitch = undefined")
CODE (L"  \\#  Take some exceptional action.")
CODE (L"else")
CODE (L"  \\#  Take the normal action.")
CODE (L"endif")
ENTRY (L"Details for hackers")
NORMAL (L"In text files, this value is written as ##--undefined--#. "
	"In binary files, it is written as a big-endian IEEE positive infinity. "
	"In memory, it is the ANSI-C constant HUGE_VAL, which equals infinity on IEEE machines.")
MAN_END

MAN_BEGIN (L"Scripting examples", L"ppgb", 20040222)
INTRO (L"Here is a number of examples of how to use scripting in the Praat program. "
	"Refer to the @scripting tutorial when necessary.")
LIST_ITEM (L"@@Script for listing time\\--F0 pairs")
LIST_ITEM (L"@@Script for listing time\\--F0\\--intensity")
LIST_ITEM (L"@@Script for listing F0 statistics")
LIST_ITEM (L"@@Script for creating a frequency sweep")
LIST_ITEM (L"@@Script for onset detection")
LIST_ITEM (L"@@Script for TextGrid boundary drawing")
LIST_ITEM (L"@@Script for analysing pitch with a TextGrid")
MAN_END

MAN_BEGIN (L"Script for listing time\\--F0 pairs", L"ppgb", 20041005)
INTRO (L"\"I wish to have a list of time markers in one column and F0 in the other. "
	"Those times that have no voiced data should be represented as \\\"l.\\\"r in the F0 column.\"")
CODE (L"echo Time:    Pitch:")
CODE (L"numberOfFrames = Get number of frames")
CODE (L"for iframe to numberOfFrames")
CODE1 (L"time = Get time from frame... iframe")
CODE1 (L"pitch = Get value in frame... iframe Hertz")
CODE1 (L"if pitch = undefined")
CODE2 (L"printline 'time:6' .")
CODE1 (L"else")
CODE2 (L"printline 'time:6' 'pitch:3'")
CODE1 (L"endif")
CODE (L"endfor")
NORMAL (L"If you want to see this in a text file, you can copy and paste from the Info window, or save the Info window, "
	"or add a line to the script like")
CODE (L"fappendinfo out.txt")
MAN_END

MAN_BEGIN (L"Script for listing time\\--F0\\--intensity", L"ppgb", 20060714)
INTRO (L"\"I want a list of pitch and intensity values at the same times.\"")
NORMAL (L"Since @@Sound: To Pitch...@ and @@Sound: To Intensity...@ do not give values at the same times, "
	"you create separate pitch and intensity contours with high time resolution, then interpolate. "
	"In the following example, you get pitch and intensity values at steps of 0.01 seconds "
	"by interpolating curves that have a time resolution of 0.001 seconds.")
CODE (L"sound = selected (\"Sound\")")
CODE (L"tmin = Get start time")
CODE (L"tmax = Get end time")
CODE (L"To Pitch... 0.001 75 300")
CODE (L"Rename... pitch")
CODE (L"select sound")
CODE (L"To Intensity... 75 0.001")
CODE (L"Rename... intensity")
CODE (L"echo Here are the results:")
CODE (L"for i to (tmax-tmin)/0.01")
CODE1 (L"time = tmin + i * 0.01")
CODE1 (L"select Pitch pitch")
CODE1 (L"pitch = Get value at time... time Hertz Linear")
CODE1 (L"select Intensity intensity")
CODE1 (L"intensity = Get value at time... time Cubic")
CODE1 (L"printline 'time:2' 'pitch:3' 'intensity:3'")
CODE (L"endfor")
MAN_END

MAN_BEGIN (L"Script for listing F0 statistics", L"ppgb", 20060714)
INTRO (L"\"I need to split the wave into 50 msec sections, and then for each of those sections "
	"get the F0 statistics. That is, for each 50 msec section of speech I want to get the average F0, "
	"min, max, and standard deviation.\"")
NORMAL (L"First you create the complete pitch contour, i.e., you select the Sound and choose "
	"@@Sound: To Pitch...|To Pitch...@. You can then use the commands from the #Query menu in a loop:")
CODE (L"startTime = Get start time")
CODE (L"endTime = Get end time")
CODE (L"numberOfTimeSteps = (endTime - startTime) / 0.05")
CODE (L"echo   tmin     tmax    mean   fmin   fmax  stdev")
CODE (L"for step to numberOfTimeSteps")
CODE1 (L"tmin = startTime + (step - 1) * 0.05")
CODE1 (L"tmax = tmin + 0.05")
CODE1 (L"mean = Get mean... tmin tmax Hertz")
CODE1 (L"minimum = Get minimum... tmin tmax Hertz Parabolic")
CODE1 (L"maximum = Get maximum... tmin tmax Hertz Parabolic")
CODE1 (L"stdev = Get standard deviation... tmin tmax Hertz")
CODE1 (L"printline 'tmin:6' 'tmax:6' 'mean:2'")
CODE1 (L"... 'minimum:2' 'maximum:2' 'stdev:2'")
CODE (L"endfor")
ENTRY (L"Notes")
NORMAL (L"One should not cut the sound up into pieces of 50 ms and then do ##To Pitch...# on each of them, "
	"because Praat will not compute F0 values in the first or last 20 ms (or so) of each piece. "
	"This is because the analysis requires a window of 40 ms (or so) for every pitch frame. "
	"Instead, one typically does the analysis on the whole sound, then queries the resulting large Pitch object. "
	"In that way, the information loss of windowing only affects the two 20 ms edges of the whole sound.")
NORMAL (L"The example writes lines to the Info window. If you want to write to a file instead, "
	"you start with something like")
CODE1 (L"filedelete ~/results/out.txt")
NORMAL (L"and add lines in the following way:")
CODE1 (L"fileappend ~/results/out.txt 'tmin:6' 'tmax:6' 'mean:2'")
CODE1 (L"... 'minimum:2' 'maximum:2' 'stdev:2''newline\\$ '")
MAN_END

MAN_BEGIN (L"Script for creating a frequency sweep", L"ppgb", 20070225)
INTRO (L"\"I have to find a formula for a sinewave that sweeps from 1 kHz to 12 kHz in "
	"60 seconds while ramping the amplitude from 1 to 12 volts in the same amount of time.\"")
NORMAL (L"The absolute amplitude in volts cannot be handled, of course, but linear crescendo is easy:")
CODE (L"Create Sound from formula... sweep Mono 0 60 44100")
CODE (L"... 0.05 * (1 + 11 * x/60) * sin (2*pi * (1000 + 11000/2 * x/60) * x)")
NORMAL (L"Note the \"/2\" in this formula. Here is the derivation of the formula:")
FORMULA (L"%frequency (%t) = 1000 + 11000 %t / 60")
FORMULA (L"%phase (%t) = \\in %frequency (%t) %dt = 1000 %t + 11000 (%t^2/2) / 60")
FORMULA (L"%signal (%t) = sin (%phase (%t))")
MAN_END

MAN_BEGIN (L"Script for onset detection", L"ppgb", 20041005)
INTRO (L"\"Can anybody provide me with a script that detects the onset of sound (i.e. the end of silence).\"")
NORMAL (L"You can create an Intensity contour and look for the first frame that is above some predefined threshold:")
CODE (L"To Intensity... 100 0")
CODE (L"n = Get number of frames")
CODE (L"for i to n")
CODE1 (L"intensity = Get value in frame... i")
CODE1 (L"if intensity > 40")
CODE2 (L"time = Get time from frame... i")
CODE2 (L"echo Onset of sound at: 'time:3' seconds.")
CODE2 (L"exit")
CODE1 (L"endif")
CODE (L"endfor")
NORMAL (L"Since the intensity is computed with rather long windows, the result may be 0.01 or 0.02 seconds "
	"before the actual start of sound.")
MAN_END

MAN_BEGIN (L"Script for TextGrid boundary drawing", L"ppgb", 20040222)
INTRO (L"\"I want only the dotted lines of the textgrid marked on top of another analysis (e.g. pitch, intensity or so) "
	"without the labels being shown below it.\"")
CODE (L"n = Get number of intervals... 1")
CODE (L"for i to n-1")
CODE1 (L"t = Get end point... 1 i")
CODE1 (L"One mark bottom... t no no yes")
CODE (L"endfor")
MAN_END

MAN_BEGIN (L"Script for analysing pitch with a TextGrid", L"ppgb", 20051112)
INTRO (L"\"I want the mean pitch of every interval that has a non-empty label on tier 5.\"")
CODE (L"if numberOfSelected (\"Sound\") <> 1 or numberOfSelected (\"TextGrid\") <> 1")
CODE1 (L"exit Please select a Sound and a TextGrid first.")
CODE (L"endif")
CODE (L"sound = selected (\"Sound\")")
CODE (L"textgrid = selected (\"TextGrid\")")
CODE (L"echo Result:")
CODE (L"select sound")
CODE (L"To Pitch... 0.0 75 600")
CODE (L"pitch = selected (\"Pitch\")")
CODE (L"select textgrid")
CODE (L"n = Get number of intervals... 5")
CODE (L"for i to n")
CODE1 (L"tekst\\$  = Get label of interval... 5 i")
CODE1 (L"if tekst\\$  <> \"\"")
CODE2 (L"t1 = Get starting point... 5 i")
CODE2 (L"t2 = Get end point... 5 i")
CODE2 (L"select pitch")
CODE2 (L"f0 = Get mean... t1 t2 Hertz")
CODE2 (L"printline 't1:3' 't2:3' 'f0:0' 'tekst\\$ '")
CODE2 (L"select textgrid")
CODE1 (L"endif")
CODE (L"endfor")
CODE (L"select sound")
CODE (L"plus textgrid")
MAN_END

}

/* End of file manual_Script.c */
