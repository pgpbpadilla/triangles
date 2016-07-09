import sys

program=sys.argv[0]

if len(sys.argv) < 3:
    sys.exit(
        ''' Usage: $ python {program} <count> <symbol>
        e.g. $ python {program} 5 "*"'''.format(program=program))

height=int(sys.argv[1])
symbol=sys.argv[2]

def print_pyramid(title):
    print "\n"
    print "-----{}-----".format(title)
    
def increasing_left(n, symbol):
    for i in range(1, n+1):
        print symbol * i

def increasing_right(n, symbol):
    for i in range(1, n+1):
        print '{spaces}{symbols}'.format(
            spaces=' ' * (len(symbol)*(n-i)), 
            symbols=symbol * i
        )
    

def decreasing_left(n, symbol):
    for i in range(n, 0, -1):
        print symbol * i

def decreasing_right(n, symbol, left_padding):
    for i in range(n):
        print '{lp}{spaces}{symbols}'.format(
            symbols=symbol * (n-i),
            spaces=' ' * (len(symbol)*i),
            lp=' ' * (len(symbol)*left_padding)
        )
    

def symmetric_left(n, symbol):
    increasing_left(n, symbol)
    decreasing_left(n-1, symbol)

def symmetric_right(n, symbol):
    increasing_right(n, symbol)
    decreasing_right(n-1, symbol, 1)

def symmetric_bottom(n, symbol):
    for i in range(n):
        print '{spaces}{symbols}'.format(
            spaces=' ' * (len(symbol)*(n-(i+1))),
            symbols=symbol * ((2*i)+1)
        )

def symmetric_top(n, symbol):
    for i in range(n):
        print '{spaces}{symbols}'.format(
            spaces=' ' * (len(symbol)*i),
            symbols=symbol * (2*(n-1-i)+1)
        )


print_pyramid("Increasing LEFT pyramid")
increasing_left(height, symbol)

print_pyramid("Increasing RIGHT pyramid")
increasing_right(height, symbol)

print_pyramid("Decreasing LEFT pyramid")
decreasing_left(height, symbol)

print_pyramid("Decreasing RIGHT pyramid")
decreasing_right(height, symbol, 0)

print_pyramid("Symmetric LEFT pyramid")
symmetric_left(height, symbol)

print_pyramid("Symmetric RIGHT pyramid")
symmetric_right(height, symbol)

print_pyramid("Symmetric BOTTOM pyramid")
symmetric_bottom(height, symbol)

print_pyramid("Symmetric TOP pyramid")
symmetric_top(height, symbol)
