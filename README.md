![CodeWizard](https://github.com/user-attachments/assets/1454ecb4-7e87-41e7-888f-b79565d2b843)


It's not a virus, I promise. It does create and run .bat files, but it's seriously not a virus. Qt (c++) just sucks.

CodeWizard is a custom Code Editor / IDE designed by Adam Mather. The main point behind CodeWizard is an editor like Python's IDLE but with a better dark mode. That was seriously the whole motivation behind the project. As I continued I decided to support more languages than just Python, mainly because I prefer the interface and philosophy to modern (better) IDEs (think VSCode, etc).

**Features (not bugs, features):**

**1. Autocomplete**

The way CodeWizard handles autocomplete is currently not as advanced as other editors. I learned after building autocomplete that most major editors today use LSP, or Language Server Protocol, to interact with dedicated programs for autocomplete, highlighting, error detection, etc. I have yet to build that into CodeWizard. Right now, CodeWizard has a baked-in list of known words for every language it supports. As an added bonus, CodeWizard will identify a complete list of words found in your code to autocomplete from.

**2. Highlighting**

Similar to autocomplete, it also has a list of words and associated colors for every language. (Try typing codewizard (any capitalization will work) into CodeWizard)

**3. Running Code**

When CodeWizard attempts to execute the program you have created, it will first create a .bat file in a temporary folder. This .bat file will be written with the appropriate commands to run the program. After it is created, CodeWizard will run it. I tried so hard to not have to use a .bat file, but whatever.

**4. CodeShizard**

The CodeWizard wannabe, CodeShizard, is yet another editor which I must emphasize is _worse_ than CodeWizard. _WORSE_

