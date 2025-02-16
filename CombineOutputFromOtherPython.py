# combiner
# uses the printed out "fulls"
# this is useful for the cases where we want to have languages which are supersets of other languages (thing c-c++ or js-ts)

in2 = {'identifier': 'variable', 'property_identifier': 'property', 'function_expression/.CodeWiz./identifier': 'function', 'function_declaration/.CodeWiz./identifier': 'function', 'method_definition/.CodeWiz./property_identifier': 'function.method', 'pair': 'function.method', 'pair/.CodeWiz./property_identifier': 'function.method', 'function_expression/.CodeWiz./arrow_function': 'function.method', 'arrow_function/.CodeWiz./assignment_expression': 'function.method', 'assignment_expression/.CodeWiz./member_expression': 'function.method', 'member_expression/.CodeWiz./property_identifier': 'function.method', 'arrow_function/.CodeWiz./variable_declarator': 'function', 'variable_declarator/.CodeWiz./identifier': 'function', 'assignment_expression/.CodeWiz./identifier': 'function', 'arrow_function/.CodeWiz./call_expression': 'function', 'call_expression/.CodeWiz./identifier': 'function', 'call_expression/.CodeWiz./member_expression': 'function.method', 'identifier/.CodeWiz./shorthand_property_identifier': 'constant', 'shorthand_property_identifier/.CodeWiz./shorthand_property_identifier_pattern': 'constant', 'arguments': 'variable.builtin', 'arguments/.CodeWiz./module': 'variable.builtin', 'module': 'variable.builtin', 'module/.CodeWiz./console': 'variable.builtin', 'console': 'variable.builtin', 'console/.CodeWiz./window': 'variable.builtin', 'window': 'variable.builtin', 'window/.CodeWiz./document': 'variable.builtin', 'document': 'variable.builtin', 'require': 'function.builtin', 'this': 'variable.builtin', 'super': 'variable.builtin', 'true/.CodeWiz./false': 'constant.builtin', 'false/.CodeWiz./null': 'constant.builtin', 'null/.CodeWiz./undefined': 'constant.builtin', 'comment': 'comment', 'string': 'string', 'string/.CodeWiz./template_string': 'string', 'template_string': 'string', 'regex': 'string.special', 'number': 'number', ';': 'punctuation.delimiter', ';/.CodeWiz./optional_chain': 'punctuation.delimiter', 'optional_chain': 'punctuation.delimiter', 'optional_chain/.CodeWiz./.': 'punctuation.delimiter', '.': 'punctuation.delimiter', './.CodeWiz./,': 'punctuation.delimiter', ',': 'punctuation.delimiter', '-': 'operator', '-/.CodeWiz./--': 'operator', '--': 'operator', '--/.CodeWiz./-=': 'operator', '-=': 'operator', '-=/.CodeWiz./+': 'operator', '+': 'operator', '+/.CodeWiz./++': 'operator', '++': 'operator', '++/.CodeWiz./+=': 'operator', '+=': 'operator', '+=/.CodeWiz./*': 'operator', '*': 'operator', '*/.CodeWiz./*=': 'operator', '*=': 'operator', '*=/.CodeWiz./**': 'operator', '**': 'operator', '**/.CodeWiz./**=': 'operator', '**=': 'operator', '**=/.CodeWiz.//': 'operator', '/': 'operator', '//.CodeWiz.//=': 'operator', '/=': 'operator', '/=/.CodeWiz./%': 'operator', '%': 'operator', '%/.CodeWiz./%=': 'operator', '%=': 'operator', '%=/.CodeWiz./<': 'operator', '<': 'operator', '</.CodeWiz./<=': 'operator', '<=': 'operator', '<=/.CodeWiz./<<': 'operator', '<<': 'operator', '<</.CodeWiz./<<=': 'operator', '<<=': 'operator', '<<=/.CodeWiz./=': 'operator', '=': 'operator', '=/.CodeWiz./==': 'operator', '==': 'operator', '==/.CodeWiz./===': 'operator', '===': 'operator', '===/.CodeWiz./!': 'operator', '!': 'operator', '!/.CodeWiz./!=': 'operator', '!=': 'operator', '!=/.CodeWiz./!==': 'operator', '!==': 'operator', '!==/.CodeWiz./=>': 'operator', '=>': 'operator', '=>/.CodeWiz./>': 'operator', '>': 'operator', '>/.CodeWiz./>=': 'operator', '>=': 'operator', '>=/.CodeWiz./>>': 'operator', '>>': 'operator', '>>/.CodeWiz./>>=': 'operator', '>>=': 'operator', '>>=/.CodeWiz./>>>': 'operator', '>>>': 'operator', '>>>/.CodeWiz./>>>=': 'operator', '>>>=': 'operator', '>>>=/.CodeWiz./~': 'operator', '~': 'operator', '~/.CodeWiz./^': 'operator', '^': 'operator', '^/.CodeWiz./&': 'operator', '&': 'operator', '&/.CodeWiz./|': 'operator', '|': 'operator', '|/.CodeWiz./^=': 'operator', '^=': 'operator', '^=/.CodeWiz./&=': 'operator', '&=': 'operator', '&=/.CodeWiz./|=': 'operator', '|=': 'operator', '|=/.CodeWiz./&&': 'operator', '&&': 'operator', '&&/.CodeWiz./||': 'operator', '||': 'operator', '||/.CodeWiz./??': 'operator', '??': 'operator', '??/.CodeWiz./&&=': 'operator', '&&=': 'operator', '&&=/.CodeWiz./||=': 'operator', '||=': 'operator', '||=/.CodeWiz./??=': 'operator', '??=': 'operator', '(': 'punctuation.bracket', '(/.CodeWiz./)': 'punctuation.bracket', ')': 'punctuation.bracket', ')/.CodeWiz./[': 'punctuation.bracket', '[': 'punctuation.bracket', '[/.CodeWiz./]': 'punctuation.bracket', ']': 'punctuation.bracket', ']/.CodeWiz./{': 'punctuation.bracket', '{': 'punctuation.bracket', '{/.CodeWiz./}': 'punctuation.bracket', '}': 'punctuation.bracket', 'template_substitution': 'punctuation.special', 'template_substitution/.CodeWiz./${': 'punctuation.special', '${': 'punctuation.special', 'as': 'keyword', 'as/.CodeWiz./async': 'keyword', 'async': 'keyword', 'async/.CodeWiz./await': 'keyword', 'await': 'keyword', 'await/.CodeWiz./break': 'keyword', 'break': 'keyword', 'break/.CodeWiz./case': 'keyword', 'case': 'keyword', 'case/.CodeWiz./catch': 'keyword', 'catch': 'keyword', 'catch/.CodeWiz./class': 'keyword', 'class': 'keyword', 'class/.CodeWiz./const': 'keyword', 'const': 'keyword', 'const/.CodeWiz./continue': 'keyword', 'continue': 'keyword', 'continue/.CodeWiz./debugger': 'keyword', 'debugger': 'keyword', 'debugger/.CodeWiz./default': 'keyword', 'default': 'keyword', 'default/.CodeWiz./delete': 'keyword', 'delete': 'keyword', 'delete/.CodeWiz./do': 'keyword', 'do': 'keyword', 'do/.CodeWiz./else': 'keyword', 'else': 'keyword', 'else/.CodeWiz./export': 'keyword', 'export': 'keyword', 'export/.CodeWiz./extends': 'keyword', 'extends': 'keyword', 'extends/.CodeWiz./finally': 'keyword', 'finally': 'keyword', 'finally/.CodeWiz./for': 'keyword', 'for': 'keyword', 'for/.CodeWiz./from': 'keyword', 'from': 'keyword', 'from/.CodeWiz./function': 'keyword', 'function': 'keyword', 'function/.CodeWiz./get': 'keyword', 'get': 'keyword', 'get/.CodeWiz./if': 'keyword', 'if': 'keyword', 'if/.CodeWiz./import': 'keyword', 'import': 'keyword', 'import/.CodeWiz./in': 'keyword', 'in': 'keyword', 'in/.CodeWiz./instanceof': 'keyword', 'instanceof': 'keyword', 'instanceof/.CodeWiz./let': 'keyword', 'let': 'keyword', 'let/.CodeWiz./new': 'keyword', 'new': 'keyword', 'new/.CodeWiz./of': 'keyword', 'of': 'keyword', 'of/.CodeWiz./return': 'keyword', 'return': 'keyword', 'return/.CodeWiz./set': 'keyword', 'set': 'keyword', 'set/.CodeWiz./static': 'keyword', 'static': 'keyword', 'static/.CodeWiz./switch': 'keyword', 'switch': 'keyword', 'switch/.CodeWiz./target': 'keyword', 'target': 'keyword', 'target/.CodeWiz./throw': 'keyword', 'throw': 'keyword', 'throw/.CodeWiz./try': 'keyword', 'try': 'keyword', 'try/.CodeWiz./typeof': 'keyword', 'typeof': 'keyword', 'typeof/.CodeWiz./var': 'keyword', 'var': 'keyword', 'var/.CodeWiz./void': 'keyword', 'void': 'keyword', 'void/.CodeWiz./while': 'keyword', 'while': 'keyword', 'while/.CodeWiz./with': 'keyword', 'with': 'keyword', 'with/.CodeWiz./yield': 'keyword', 'yield': 'keyword'}
in1 = {'type_identifier': 'type', 'predefined_type': 'type.builtin', 'identifier': 'type', 'type_arguments': 'punctuation.bracket', 'type_arguments/.CodeWiz./<': 'punctuation.bracket', '<': 'punctuation.bracket', '>': 'punctuation.bracket', 'abstract': 'keyword', 'abstract/.CodeWiz./declare': 'keyword', 'declare': 'keyword', 'declare/.CodeWiz./enum': 'keyword', 'enum': 'keyword', 'enum/.CodeWiz./export': 'keyword', 'export': 'keyword', 'export/.CodeWiz./implements': 'keyword', 'implements': 'keyword', 'implements/.CodeWiz./interface': 'keyword', 'interface': 'keyword', 'interface/.CodeWiz./keyof': 'keyword', 'keyof': 'keyword', 'keyof/.CodeWiz./namespace': 'keyword', 'namespace': 'keyword', 'namespace/.CodeWiz./private': 'keyword', 'private': 'keyword', 'private/.CodeWiz./protected': 'keyword', 'protected': 'keyword', 'protected/.CodeWiz./public': 'keyword', 'public': 'keyword', 'public/.CodeWiz./type': 'keyword', 'type': 'keyword', 'type/.CodeWiz./readonly': 'keyword', 'readonly': 'keyword', 'readonly/.CodeWiz./override': 'keyword', 'override': 'keyword', 'override/.CodeWiz./satisfies': 'keyword', 'satisfies': 'keyword'}

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
	}

fulls = {}

for i in in1:
	fulls[i] = in1[i]

for i in in2:
	if i not in fulls:
		fulls[i] = in2[i]

out = ""

print(fulls)
print("\n\n")

for i in fulls:
	out += "{\""+i.replace("\\", "\\\\").replace("\"", "\\\"")+"\", "+str(dct[fulls[i]])+"}, "

import pyperclip
pyperclip.copy(out[:-2])
print(out[:-2])