#include "Eg.h"

//行编辑器
//输入字符序列（#表示前一个字符无效，@表示当前行字符无效)
void HangBianJiQi()
{
	Stack s;
	StackInit(&s);

	printf("请输入一字符串：\n");
	char c = getchar();

	while (c != '\n')
	{
		switch (c)
		{
		case '#':
			if (!StackEmpty(&s))
			{
				StackPop(&s);
			}
			break;
		case '@':
			while (!StackEmpty(&s))
			{
				StackPop(&s);
			}
			break;
		default:
			StackPush(&s, c);
			break;
		}
		c = getchar();
	}

	while (!StackEmpty(&s))
	{
		printf("%c", StackTop(&s));
		StackPop(&s);

	}
	///此时打印为逆序串，可以在用一个数组，将串存于数组中，在逆序打印数组即可
	StackDestory(&s);

}

//括号匹配
static int IsBlank(char c)
{
	if (c == '{' || c == '}'
		|| c == '[' || c == ']'
		|| c == '(' || c == ')')
		return 1;
	else
		return 0;
}
int IsOk(char* p)
{
	assert(p);
	Stack s;
	StackInit(&s);
	
	int len = strlen(p);
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		char c = p[i];
		if (!IsBlank(c))
			continue;
		else
		{
			if (c == '(' || c == '[' || c == '{')
			{
				StackPush(&s, c);
			}
			else
			{
				char q;
				if (StackEmpty(&s))
				{
					printf("右多余左边\n");
					StackDestory(&s);

					return 0;

				}
				q = StackTop(&s);
				if ((q == '{'&&p[i] == '}')
					|| (q == '['&&p[i] == ']')
					|| (q == '('&&p[i] == ')'))
					StackPop(&s);
				else
				{
					printf("匹配有问题\n");
					StackDestory(&s);

					return 0;

				}
			}
		}
		 
		 
	}
	if (!StackEmpty(&s))
	{
		printf("左多余右\n");
		StackDestory(&s);
		return 0;
	}
	StackDestory(&s);

	printf("正确\n");
	return 1;

}
void testIsOk()
{
	char* p = "{{{{{((()))[][]}}}}}";
	int ret = IsOk(p);
	if (1 == ret)
	{
		printf("匹配\n");

	}
	else
		printf("不匹配\n");
}
//逆波兰表达式
//1.将中缀表达式转换为后缀表达式
/*(1) 初始化两个栈：运算符栈S1和储存中间结果的栈S2；

(2) 从左至右扫描中缀表达式；

(3) 遇到操作数时，将其压入S2；

(4) 遇到运算符时，比较其与S1栈顶运算符的优先级：

? (4-1)如果S1为空，或栈顶运算符为左括号“(”，则直接将此运算符入栈；

? (4-2)否则，若优先级比栈顶运算符的高，也将运算符压入S1（注意转换为前缀表达式时是优先级较高或相同，而这里则不包括相同的情况）；

? (4-3)否则，将S1栈顶的运算符弹出并压入到S2中，再次转到(4-1)与S1中新的栈顶运算符相比较；

(5) 遇到括号时：

? 如果是左括号“(”，则直接压入S1；

? 如果是右括号“)”，则依次弹出S1栈顶的运算符，并压入S2，直到遇到左括号为止，此时将这一对括号丢弃；

(6) 重复步骤(2)至(5)，直到表达式的最右边；

(7) 将S1中剩余的运算符依次弹出并压入S2；

(8) 依次弹出S2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式（转换为前缀表达式时不用逆序）。*/

void trans(SElemType str[], SElemType rpn[])
{
	i = 0, t = 0;
	ch = str[i++];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(': Push(op, ch); break;
		case ')': while (GetTop(op) != '(')
		{
					  rpn[t] = GetTop(op);
					  Pop(op);
					  t++;
		}
				  op.top--;//此处必须再次进行--运算，才能忽略已经进入的‘（’ 
				  break;
		case '+':
		case '-':
			while (op.top != op.base && GetTop(op) != '(')
			{
				rpn[t] = GetTop(op);
				Pop(op);
				t++;
			}
			Push(op.ch);
			break;
		case '*':
		case '/':
			while (GetTop(op)'*' || GetTop(op) == '/')
			{
				rpn[t] = GetTop(op);
				Pop(op);
				t++;
			}
			Push(op.ch);
			break;
		case ' ':break;
		default:
			while (ch >= '0'&&ch <= '9')
			{
				rpn[t] = ch;
				t++;
				ch = str[i];
				i++;
			}
			i--;
			rpn[t] = '#'; t++;
		}//switch
		ch = str[i];
		i++;
	}//while
	while (op.top != op.base)
	{
		rpn[t] = GetTop(op);
		t++;
		Pop(op);
	}//while
	rpn[t] = '\0';
}//trans


//2.应用两个栈，对后缀进行计算
/*从左至右扫描表达式，遇到数字时，将数字压入堆栈，遇到运算符时，弹出栈顶的两个数，用运算符对它们做相应的计算（次顶元素 op 栈顶元素），并将结果入栈；重复上述过程直到表达式最右端，最后运算得出的值即为表达式的结果。

例如后缀表达式“5 13 4 +*3 /7-”：

(1) 从左至右扫描，将5、13和4压入堆栈；

(2) 遇到+运算符，因此弹出4和13（4为栈顶元素，13为次顶元素，注意与前缀表达式做比较），计算出13+4的值，得17，再将17入栈；

(3) 接下来是*运算符，因此弹出17和5，计算出5*17=-85，将85入栈；

(4) 将3入栈

(5) 接下来是/运算符，因此弹出3和85，计算出85/3=28，将28入栈；

(6) 将7入栈

(7) 最后是-运算符，因此弹出7和28,计算出28-7=21，由此得出最终结果。*/
int value(char rpn[])
{
	t = 0, ch = rpn[t], t++;
	while (ch != '\0')
	{
		switch (ch)
		{
		case '+': m = Pop(st); n = Pop(st);
			Push(st, n + m);
			break;
		case '-': m = Pop(st); n = Pop(st);
			Push(st, n - m);
			break;
		case '*': m = Pop(st); n = Pop(st);
			Push(st, n*m);
			break;
		case '/': if (GetTop(st) != 0)
		{
					  m = Pop(st); n = Pop(st);
					  Push(st, n / m); break;
		}
				  else
				  {
					  printf("\n除0错误！\n");
					  exit(0);
				  }
		default: d = 0;
			while (ch >= '0'&&ch <= '9')
			{
				d = 10 * d + ch - '0';
				ch = rpn[t];
				t++;
			}
			Push(st, d);
		}//switch
		ch = rpn[t]; t++;
	}//while
	return GetTop(st);
}//value