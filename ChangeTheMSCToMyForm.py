import os
import re
from collections import defaultdict

filedir = "testhighlight"
file = 'cobol.msc'

def isRegex(txt):
	cnt = txt.count("^")
	cnt += txt.count("-")
	cnt += txt.count("A")
	cnt += txt.count("$")
	if cnt > 2:
		return True
	return False #comment

pattern = r'\((\w+)\)'
pattern2 = r'@([\w.]+)'
pattern3 = r'\"(.*?)\"'
pattern4 = r'\'(\w+)\''
pattern5 = r'\(([\w|]+)\)'

fulls = {}
fulls2 = defaultdict(set)

with open(filedir+"/"+file, "r") as f:
	lines = f.readlines()

inLst = False
unknownYet = []
bigMatch = False
subd = 0
#count = 0

for i, line in enumerate(lines):
	if line[0] == ';' or line.strip() == '':
		continue
	
	print(line)
	
	matches = re.findall(pattern, line.strip()+")")
	if "name: (" in line and matches:
		subd += 1
	
	unknownYet += [i for i in matches if i not in unknownYet]
	
	match = re.search(pattern5, line)
	if match:
		if "|" in match.group(1):
			bigMatch = True
		unknownYet += [i for i in match.group(1).split('|') if i.isidentifier() and i not in unknownYet]
	else:
		matches = re.findall(pattern3, line)
		unknownYet +=[i for i in matches if i not in unknownYet]
		if len(matches) > 0 and line.startswith(" "): # is list - I think
			bigMatch = True
	
	matches = re.findall(pattern4, line)
	unknownYet += [i for i in matches if i not in unknownYet]
	match = re.search(pattern2, line)
	
	print("   ", unknownYet, subd, bigMatch)

	if match:
		for z, i in enumerate(unknownYet):
			if isRegex(i):
				continue
			
			if z != 0:
				toUse = ""
				for j in unknownYet[:z]:
					if j != i:
						toUse = j
				
				if toUse != "" and toUse != i:
					if toUse+"/.CodeWiz./"+i not in fulls:
						fulls[toUse+"/.CodeWiz./"+i] = match.group(1)
					fulls2[match.group(1)].add(toUse+"/.CodeWiz./"+i)
			
			if len(unknownYet)+subd < 3 or bigMatch:# or count > 3:
				if i not in fulls:
					fulls[i] = match.group(1)
				
				fulls2[match.group(1)].add(i)
				
		unknownYet = []
		bigMatch = False
		subd = 0
#		count = 0
#	else:
#		count += 1
		
	if line[0:2] == '  ':
		inLst = True
	else:
		inLst = False

print(fulls)
print()

for i in fulls2:
	print(i)
	for j in fulls2[i]:
		print("   ", j)
#8 is now literal - your welcome future me...

dct = {
	"identifier":3,
	"tag":6,
	"error":0,
	"conditional":6,
	"repeat":5,
	"storageclass":4,
	"field":3,
	"structure":3,
	"parameter":4,
	"boolean":8,
	"float":8,
	"delimiter":7,
	"attribute":4,
	"label":4,
	"punctuation":7,
	"constructor":3,
	"comment":2,
	"constant":3,
	"number":8,
	"escape":1,
	"string":1,
	"keyword":6,
	"operator":7,
	"variable":3,
	"property":4,
	"type":4,
	"function":5,
	"function.builtin":5,
	"function.method":5,
	"punctuation.special":7,
	"type.builtin":4,
	"function.macro":5,
	"comment.documentation":2,
	"punctuation.bracket":7,
	"punctuation.delimiter":7,
	"variable.paramater":3,
	"variable.builtin":3,
	"string.escape":1,
	"function.special":5,
	"property.definition":3,
	"type.qualifier":4,
	"keyword.function":6,
	"keyword.storage":6,
	"function.call":5,
	"keyword.return":6,
	"string.special":1,
	"keyword.repeat":6,
	"keyword.conditional":6,
	"tag.error":6,
	"keyword.operator":6,
	"function.bracket":7,
	"function.call.lua":5,
	"constant.builtin":3,
	"variable.parameter":3,
	"first":3
}

out = ""

print(fulls)
print("\n\n")

for i in fulls:
	print(i)
	out += "{\""+i.replace("\\", "\\\\").replace("\"", "\\\"")+"\", "+str(dct[fulls[i]])+"}, "

import pyperclip
pyperclip.copy(out[:-2])
print(out[:-2])