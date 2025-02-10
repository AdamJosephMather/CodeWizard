![Artboard 1@5x](https://github.com/user-attachments/assets/d007d8a2-101f-4d35-a691-aac32ce1ae5b)

# CodeWizard

It's not a virus, I promise. It does create and run .bat files, but it's seriously not a virus. Qt (c++) just sucks.

CodeWizard is a custom Code Editor / IDE designed by Adam Mather. The main point behind CodeWizard is an editor like Python's IDLE but with a better dark mode. That was seriously the whole motivation behind the project. As I continued I decided to support more languages than just Python, mainly because I prefer the interface and philosophy to modern (better) IDEs (think VSCode, etc).

## Screenshots

<img width="1128" alt="FullWFiletree" src="https://github.com/user-attachments/assets/e326ef1a-5cf3-4ba4-98ba-ca5a6bd718c6" />

CodeWizard has an optional filetree on the left. Here's an example without.

<img width="564" alt="HalfWBottom" src="https://github.com/user-attachments/assets/03625ed1-bb6a-4bc7-b233-a13e0f567d6d" />

Furthermore, the bottom bar can be closed and the filetree can be closed in fullscreen.

<img width="1128" alt="LargeWoutFiletreeWoutBottom" src="https://github.com/user-attachments/assets/c11f404c-3a74-4b77-9fe1-b5c5cf98718d" />

Here, I am demonstrating the comparison function in CodeWizard.

<img width="1128" alt="image" src="https://github.com/user-attachments/assets/eb7eef86-95e3-4757-981c-9f4c542f492f" />


## Why use CodeWizard?

CodeWizard offers a couple of major improvements on the existing editors:  
1. System resource usage. CodeWizard clocks in at 20 MB of RAM usage on my machine. Compare that to VSCode which consumes upwards of 600 MB of RAM when opened.  
2. Simplicity. CodeWizard is ideal for people used to and or wanting the IDLE like experience without excess bloat. Of course it does support the more complicated features like LSPs and whatnot, but it's an optional addon.  
3. AI. CodeWizard can connect to Groq AI with an API key provided by the user for code generation.  
4. Fun features. For example, CodeWizard will let you select an image to theme it off of. This themeing will apply to the syntax colors it uses. More info in the Syntax Highlighting section.

## Language Server Protocol

CodeWizard Version 8.0.0 and onwards support LSPs. Specifically, you can specify the command to start an LSP for CodeWizard to use for the current language. See the help menu in CodeWizard for more info on how to setup an LSP. Furthermore, CodeWizard does have a builtin autocomplete which activates when there is no LSP set, or when the user specifies to rely on CodeWizard's builtin rather than the LSP.

## Syntax Highlighting

Version 8.5.0 now utilizes tree-sitter with incremental updates to highlight your code. You can now customize the colors CodeWizard will use to highlight your code under View->Set Syntax Colors. Furthermore, it all comes preinstalled and at no cost to performance. Note: Plaintext documents do not receive syntax highlighting. By far the best part is getting to have CodeWizard select colors from an image to use as the syntax highlighting colors. Again under the same menu.

## AI

Version 8.8.0 can now request code generation by a 70 billion paramater model at Groq AI. It's very fast, and it works well. To provide the API key goto [Groq AI](https://groq.com/) and get a free API key. Then put the code into CodeWizard at Fix It -> Set Groq AI API Key. Once that has been finished you can press Alt+A to generate code at the cursor position.

## Other

**Running Code**

When CodeWizard attempts to execute the program you have created, it will first create a .bat file in a temporary folder. This .bat file will be written with the appropriate commands to run the program. After it is created, CodeWizard will run it. I tried so hard to not have to use a .bat file, but whatever.

**Vim mode**

CodeWizard has an optional vim mode which enables a modal setup with both a normal and insert mode. It is worth noting that it is a modification to a subset of Vim bindings. 

**Builtin Terminal**

CodeWizard now has an optional builtin terminal. It's far from perfect, and I don't recommend using it for a wide variety of tasks. If you're program does not do what is expected when using the builtin terminal, it is probably because of the stdio buffering issue. Look for an option to disable buffering or buffer by line (in Python the fix is the -u argument in the CodeWizard tagline).
