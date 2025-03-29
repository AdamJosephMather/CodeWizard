![Artboard 1@5x](https://github.com/user-attachments/assets/d007d8a2-101f-4d35-a691-aac32ce1ae5b)

# CodeWizard

It's not a virus, I promise. It does create and run .bat files, but it's seriously not a virus. Qt (c++) just sucks.

CodeWizard is a custom Code Editor / IDE designed by Adam Mather. The main point behind CodeWizard is an editor like Python's IDLE but with a better dark mode. That was seriously the whole motivation behind the project. As I continued I decided to support more languages than just Python, mainly because I prefer the interface and philosophy to modern (better) IDEs (think VSCode, etc).

## Screenshots

<img width="564" alt="4h3" src="https://github.com/user-attachments/assets/435bc15e-91e0-4f74-8149-61bbe9931c81" />
<img width="564" alt="4h" src="https://github.com/user-attachments/assets/fe2c9f7d-e683-48b7-b5a7-373c311cc9aa" />
<img width="1128" alt="4" src="https://github.com/user-attachments/assets/0feddde4-f8f3-4427-ba9b-6e4738c9e29b" />
<img width="1128" alt="5" src="https://github.com/user-attachments/assets/333d0af0-fa19-4792-8956-adf86a224bc7" />
<img width="1128" alt="13" src="https://github.com/user-attachments/assets/0f5831a8-e089-4c40-9c51-5d9d5ccd51b2" />
<img width="1128" alt="3" src="https://github.com/user-attachments/assets/fe4522bf-403c-4011-bf5a-2abc25355fc3" />
<img width="1128" alt="2" src="https://github.com/user-attachments/assets/ffd0fbcf-d0a1-48e1-9e1b-36fea80afcdb" />
<img width="1128" alt="12" src="https://github.com/user-attachments/assets/aad17b53-2f83-455d-87c2-e77cb7f1bffd" />
<img width="1128" alt="1" src="https://github.com/user-attachments/assets/d3321667-74d3-4d11-9e75-23570fee7cb5" />
<img width="1128" alt="6" src="https://github.com/user-attachments/assets/40230f62-6f28-4a3a-902b-6ab6bb24b6bf" />
<img width="564" alt="7" src="https://github.com/user-attachments/assets/5fb07a1f-d804-4ed2-93e6-5a9b5a8b90b3" />

These screenshots show a wide variety of features in CodeWizard. Including the builtin terminal, filetree, comparison feature, syntax colors, multiple cursors, command palette, and bottom edit bar.

## Why use CodeWizard?

CodeWizard offers a couple of major improvements on the existing editors:  
1. System resource usage. CodeWizard clocks in at ~~30~~ 150 MB of RAM usage on my machine. (increased due to new built in web view) Compare that to VSCode which consumes upwards of 600 MB of RAM when opened.  
2. Simplicity. CodeWizard is ideal for people used to and or wanting the IDLE like experience without excess bloat. Of course it does support the more complicated features like LSPs and whatnot, but it's an optional addon.  
3. AI. CodeWizard can connect to Groq AI with an API key provided by the user for code generation. (this will burn through credits, particularly on larger files)  
4. Fun features. For example, CodeWizard will let you select an image to theme it off of. This themeing will apply to the syntax colors it uses. More info in the Syntax Highlighting section.

## Language Server Protocol

CodeWizard Version 8.0.0 and onwards support LSPs. Specifically, you can specify the command to start an LSP for CodeWizard to use for the current language. See the help menu in CodeWizard for more info on how to setup an LSP. Furthermore, CodeWizard does have a builtin autocomplete which activates when there is no LSP set, or when the user specifies to rely on CodeWizard's builtin rather than the LSP.

## Syntax Highlighting

Version 8.5.0 now utilizes tree-sitter with incremental updates to highlight your code. You can now customize the colors CodeWizard will use to highlight your code under View->Set Syntax Colors. Furthermore, it all comes preinstalled and at no cost to performance. Note: Plaintext documents do not receive syntax highlighting. By far the best part is getting to have CodeWizard select colors from an image to use as the syntax highlighting colors. Again under the same menu.

## AI

Version 8.8.0 can now request code generation by a 70 billion paramater model at Groq AI. It's very fast, and it works well. To provide the API key goto [Groq AI](https://groq.com/) and get a free API key. Then put the code into CodeWizard at Fix It -> Set Groq AI API Key. Once that has been finished you can press Alt+A to generate code at the cursor position.

## Other

**Running Code**

When CodeWizard attempts to execute the program you have created, it will first create a .bat file in a temporary folder. This .bat file will be written with the appropriate commands to run the program. After it is created, CodeWizard will run it. I tried so hard to not have to use a .bat file, but whatever. (or .sh on linux)

**Vim mode**

CodeWizard has an optional "Vim" mode which enables a modal setup with both a normal and insert mode. It is worth noting that it is a modification to a _small_ subset of Vim bindings. 

**Builtin Terminal**

CodeWizard now has an optional builtin terminal. It's far from perfect, and I don't recommend using it for a wide variety of tasks. If your program does not do what is expected when using the builtin terminal, it is probably because of the stdio buffering issue. Look for an option to disable buffering or buffer by line (in Python the fix is the -u argument in the CodeWizard tagline). You can use more than one terminal at the same time btw.  

**Multiple Cursors**

As of CodeWizard V8.9.5, using Alt+Click or Alt+Up/Down Arrow you can instantiate more cursors. Clear them by regular clicking or the escape key. Yes you can do multiple cursors inside a macro but only with Up/Down Arrows.

**Command Palette**

As of CodeWizard V9.4.0 we now have a command palette which is used for:
1. Opening files fast
2. Execute editor commands
3. Do math (including brackets, exponents, etc)

**Settings Export**

CodeWizard, as of V8.9.5 can now export all of your settings in a .cdwzrd file. It works to export all settings except the recent files list. Also you can export just your syntax colors under View->Set Syntax Colors->Save to File

**Setup CodeWizard**

On first open (after clean install) you may find that there may be UI inconsistencies. The recommended proceedure is hitting Ctrl+T once or twice. Following that you will probably want to set your Syntax Colors, LSP, filetree, file tabs, and terminal settings. And possibly the Vim mode along with other edit settings. (Under Edit menu (includes Auto-Save)) There's more help for much of these under the Help menus.

**Operating Systems**

1. Windows - Originally designed for - works perfectly (most of the time)
2. Linux - There is a new Linux build available for amd64 Debian based environments. It's not been properly tested, and is very experemental.

---

No I don't know why I did this.  
![WTTF](https://github.com/user-attachments/assets/aa6bc6bf-42a5-4b79-ab71-906c1c683db0)

