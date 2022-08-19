# Caesar Encryption
# This is an implementation of the oldest (and probably the weakest) encryption.
# Given a string, the program shifts each characters by an arbitrary amount (key)
# yielding a new string (encrypted message)

from bidict import bidict

# bidirectional dictionary of letters & their alphabetic places
letters = bidict({'a':1, 'b':2, 'c':3 , 'd':4 , 'e':5, 'f':6, 'g':7, 'h':8, 'i':9, 'j':10,
                'k':11, 'l':12, 'm':13, 'n':14, 'o':15, 'p':16, 'q':17, 'r':18, 's':19,
                't':20, 'u':21, 'v':22, 'w':23, 'x':24, 'y':25, 'z':26})

def Caesar(Message,shift):
        Encrypted_Message = ""
        m = Message.lower()

        for i in range(len(m)):
                char = m[i]
                if char == " ":
                        char += " "
                else:
                        c = (letters[char] + shift)%26
                        if c == 0:
                                Encrypted_Message += letters.inverse[26]
                        else:
                                Encrypted_Message += letters.inverse[c]

        return Encrypted_Message
