input = open("d18_in.txt").read()
input = input.split('\n')

def weird_eval(eq):
    num_stack = []
    op_stack = []
    for component in eq:
        if component.isdigit():
            num_stack.append(int(component))
            if len(num_stack) > 1 and len(op_stack) > 0:
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
        elif component in '()+*':
            op_stack.append(component)
            if op_stack[-1] == ')':
                op_stack.pop()

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
                
                if len(op_stack) > 1:
                    op_stack.pop()
                
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
        #print(num_stack,op_stack)
    return num_stack[0]

ans = 0
for line in input:
    line=line.replace(' ','')
    cur_ans = weird_eval(line)
    print(cur_ans)
    ans += cur_ans
print(ans)