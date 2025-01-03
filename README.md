![Artboard 1@5x](https://github.com/user-attachments/assets/d007d8a2-101f-4d35-a691-aac32ce1ae5b)

# CodeWizard

It's not a virus, I promise. It does create and run .bat files, but it's seriously not a virus. Qt (c++) just sucks.

CodeWizard is a custom Code Editor / IDE designed by Adam Mather. The main point behind CodeWizard is an editor like Python's IDLE but with a better dark mode. That was seriously the whole motivation behind the project. As I continued I decided to support more languages than just Python, mainly because I prefer the interface and philosophy to modern (better) IDEs (think VSCode, etc).

## Screenshots

<img width="1128" alt="image" src="https://github.com/user-attachments/assets/49cb11af-2087-4b83-a517-0252afcf2495" />


CodeWizard has an optional filetree on the left. Here's an example without.

<img width="564" alt="image" src="https://github.com/user-attachments/assets/2f355013-3dd9-4e0d-a927-a46e3bfa191f" />

## Why use CodeWizard?

CodeWizard offers a couple of major improvements on the existing editors:  
1. System resource usage. CodeWizard clocks in at 20 MB of RAM usage on my machine. Compare that to VSCode which consumes upwards of 600 MB of RAM when opened.  
2. Simplicity. CodeWizard is ideal for people used to and or wanting the IDLE like experience without excess bloat. Of course it does support the more complicated features like LSPs and whatnot, but it's an optional addon.  
3. Fun features. For example, CodeWizard will let you select an image to theme it off of. This themeing will apply to the syntax colors it uses. More info in the Syntax Highlighting section.

## Language Server Protocol

CodeWizard Version 8.0.0 and onwards support LSPs. Specifically, you can specify the command to start an LSP for CodeWizard to use for the current language. See the help menu in CodeWizard for more info on how to setup an LSP. Furthermore, CodeWizard does have a builtin autocomplete which activates when there is no LSP set, or when the user specifies to rely on CodeWizard's builtin rather than the LSP.

## Syntax Highlighting

Version 8.5.0 now utilizes tree-sitter with incremental updates to highlight your code. You can now customize the colors CodeWizard will use to highlight your code under View->Set Syntax Colors. Furthermore, it all comes preinstalled and at no cost to performance. Note: Plaintext documents do not receive syntax highlighting. By far the best part is getting to have CodeWizard select colors from an image to use as the syntax highlighting colors. Again under the same menu.

## Other

**Running Code**

When CodeWizard attempts to execute the program you have created, it will first create a .bat file in a temporary folder. This .bat file will be written with the appropriate commands to run the program. After it is created, CodeWizard will run it. I tried so hard to not have to use a .bat file, but whatever.
