import sys

def setupIOTxt():
    with open('inputPy.txt', 'r') as infile:
        sys.stdin = infile
        input_lines = sys.stdin.read().splitlines()
        processed_lines = [line for line in input_lines]

        with open('outputPy.txt', 'w') as outfile:
            sys.stdout = outfile
            for line in processed_lines:
                print(line)
    return 



if __name__ == "__main__":
    setupIOTxt()

    str = input("Please enter the string")
    print(str)