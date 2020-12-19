input = open("d18_in.txt").read()
input = input.split('\n')

def weird_eval(eq):
    num_stack = []
    op_stack = []
    for component in eq:
        if component.isdigit():
            num_stack.append(int(component))
        elif component in '()+*':
            if component == '*':
                while len(op_stack) > 0 and op_stack[-1] == '+':
                    tmp_num1 = num_stack[-1]
                    tmp_num2 = num_stack[-2]

                    num_stack.pop()
                    num_stack.pop()
                    op_stack.pop()

                    num_stack.append(tmp_num1 + tmp_num2)
                op_stack.append(component)
            elif component == ')':
                while len(op_stack) > 0 and not op_stack[-1] == '(':
                    if op_stack[-1] == '+':
                        tmp_num1 = num_stack[-1]
                        tmp_num2 = num_stack[-2]

                        num_stack.pop()
                        num_stack.pop()
                        op_stack.pop()

                        num_stack.append(tmp_num1 + tmp_num2)
                    elif op_stack[-1] == '*':
                        tmp_num1 = num_stack[-1]
                        tmp_num2 = num_stack[-2]

                        num_stack.pop()
                        num_stack.pop()
                        op_stack.pop()

                        num_stack.append(tmp_num1 * tmp_num2)
                if len(op_stack) > 0:
                    op_stack.pop()
            else:
                op_stack.append(component)
    while len(op_stack) > 0:
        if op_stack[-1] == '+':
            tmp_num1 = num_stack[-1]
            tmp_num2 = num_stack[-2]

            num_stack.pop()
            num_stack.pop()
            op_stack.pop()

            num_stack.append(tmp_num1 + tmp_num2)
        elif op_stack[-1] == '*':
            tmp_num1 = num_stack[-1]
            tmp_num2 = num_stack[-2]

            num_stack.pop()
            num_stack.pop()
            op_stack.pop()

            num_stack.append(tmp_num1 * tmp_num2)
            
    return num_stack[0]

ans = 0
for line in input:
    line=line.replace(' ','')
    cur_ans = weird_eval(line)
    print(cur_ans)
    ans += cur_ans
print(ans)