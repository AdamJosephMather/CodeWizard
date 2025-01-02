![Artboard 1@5x](https://github.com/user-attachments/assets/d007d8a2-101f-4d35-a691-aac32ce1ae5b)

# CodeWizard

It's not a virus, I promise. It does create and run .bat files, but it's seriously not a virus. Qt (c++) just sucks.

CodeWizard is a custom Code Editor / IDE designed by Adam Mather. The main point behind CodeWizard is an editor like Python's IDLE but with a better dark mode. That was seriously the whole motivation behind the project. As I continued I decided to support more languages than just Python, mainly because I prefer the interface and philosophy to modern (better) IDEs (think VSCode, etc).

## Screenshots

<img width="1128" alt="image" src="https://github.com/user-attachments/assets/51700913-e2b4-429d-93e7-0d63bfd0fc3d" />


CodeWizard has an optional filetree on the left. Here's an example without.

<img width="564" alt="image" src="https://github.com/user-attachments/assets/f2af939e-2352-40c5-866a-b198801540e3" />

Example with different coloring selected

<img width="1128" alt="image" src="https://github.com/user-attachments/assets/4f0ba778-f7d9-4e28-ac0c-5f46116016a2" />


In case you're wondering, the hex values are as follows for this theming:  
Strings:    #9fcff7  
Comments:   #727983  
Variables:  #6caae3  
Types:      #e57069  
Functions:  #be99e7  
Extra:      #da6862  
Characters: #a0a0a0  
Literals:   #f57842  

## Why use CodeWizard?

CodeWizard offers a couple of major improvements on the existing editors. The first and most important one is system resource usage. CodeWizard clocks in at 20 MB of RAM usage on my machine. Compare that to VSCode which consumes upwards of 600 MB of RAM when opened. The second advantage CodeWizard has is simplicity. CodeWizard is ideal for people used to and or wanting the IDLE like experience without excess bloat. Of course it does support the more complicated features like LSPs and whatnot, but it's an optional addon.

## Language Server Protocol

CodeWizard Version 8.0.0 and onwards support LSPs. Specifically, you can specify the command to start an LSP for CodeWizard to use for the current language. See the help menu in CodeWizard for more info on how to setup an LSP. Furthermore, CodeWizard does have a builtin autocomplete which activates when there is no LSP set, or when the user specifies to rely on CodeWizard's builtin rather than the LSP.

## Syntax Highlighting

Version 8.5.0 now utilizes tree-sitter with incremental updates to highlight your code. You can now customize the colors CodeWizard will use to highlight your code under View->Set Syntax Colors. Furthermore, it all comes preinstalled and at no cost to performance. Note: Plaintext documents do not receive syntax highlighting.

## Other

**Running Code**

When CodeWizard attempts to execute the program you have created, it will first create a .bat file in a temporary folder. This .bat file will be written with the appropriate commands to run the program. After it is created, CodeWizard will run it. I tried so hard to not have to use a .bat file, but whatever.
