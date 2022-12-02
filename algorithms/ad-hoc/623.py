from sys import stdin, stdout

def main():
  while True:
    try:
      x = int(stdin.readline())
      ans = 1
      for i in range(1, x+1):
        ans =  ans * i
      stdout.writelines(str(x)+"!\n"+str(ans)+"\n")
      
    except EOFError:
     break  

main()
