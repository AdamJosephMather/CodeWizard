![Artboard 1@5x](https://github.com/user-attachments/assets/d007d8a2-101f-4d35-a691-aac32ce1ae5b)

# CodeWizard

It's not a virus, I promise. It does create and run .bat files, but it's seriously not a virus. Qt (c++) just sucks.

CodeWizard is a custom Code Editor / IDE designed by Adam Mather. The main point behind CodeWizard is an editor like Python's IDLE but with a better dark mode. That was seriously the whole motivation behind the project. As I continued I decided to support more languages than just Python, mainly because I prefer the interface and philosophy to modern (better) IDEs (think VSCode, etc).

## Screenshots

<img width="1128" alt="Screenshot-1" src="https://github.com/user-attachments/assets/538a0b02-3b6b-4a2f-8861-b1a045c444fd" />
<img width="564" alt="Screenshot-2" src="https://github.com/user-attachments/assets/28bd54b8-39ca-4870-848e-9d6bcde90df3" />
<img width="1128" alt="Screenshot-3" src="https://github.com/user-attachments/assets/24addb29-0e4d-4352-8ddd-d71ee6c2d94c" />
<img width="1128" alt="Screenshot-4" src="https://github.com/user-attachments/assets/4e3abc11-1c3c-4216-8875-e71f5147f0b9" />
<img width="1128" alt="Screenshot-5" src="https://github.com/user-attachments/assets/d0d5fa64-ffdb-4e10-ab48-3714da3e1601" />
<img width="1128" alt="Screenshot-6" src="https://github.com/user-attachments/assets/b5ffcfc1-9ca9-4d8e-84a6-042b40d942c5" />

These screenshots show a wide variety of features in CodeWizard. Including the builtin terminal, filetree, comparison feature, syntax colors, multiple cursors, and bottom edit bar.

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

CodeWizard now has an optional builtin terminal. It's far from perfect, and I don't recommend using it for a wide variety of tasks. If your program does not do what is expected when using the builtin terminal, it is probably because of the stdio buffering issue. Look for an option to disable buffering or buffer by line (in Python the fix is the -u argument in the CodeWizard tagline).  

**Multiple Cursors**

As of CodeWizard V8.9.5, using Alt+Click or Alt+Up/Down Arrow you can instantiate more cursors. Clear them by regular clicking or the escape key. Yes you can do multiple cursors inside a macro but only with Up/Down Arrows.

**Settings Export**

CodeWizard, as of V8.9.5 can now export all of your settings in a .cdwzrd file. It works to export all settings except the recent files list. Also you can export just your syntax colors under View->Set Syntax Colors->Save to File

**Setup CodeWizard**

On first open (after clean install) you may find that there may be UI inconsistencies. The recommended proceedure is hitting Ctrl+T once or twice. Following that you will probably want to set your Syntax Colors, LSP, filetree, and terminal settings. And possibly the Vim mode along with other edit settings. (Under Edit menu (includes Auto-Save))

**Operating Systems**

1. Windows - Originally designed for - works perfectly (most of the time)
2. Linux - There is a new Linux build available for amd64 Debian based environments. It's not been properly tested, and is very experemental.

---

No I don't know why I did this.  
![WTTF](https://github.com/user-attachments/assets/aa6bc6bf-42a5-4b79-ab71-906c1c683db0)

