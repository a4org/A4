//
// Create by Angold4 on 2021.4
//
import java.io.*;
import java.util.*;

public class addingWords {
    // lexer (scan the input and return the unit of String)
    char peek = ' ';
    ArrayList<String> answer = new ArrayList<>();

    void putAnswer(String s) { answer.add(s); }
 
    HashMap<String,String> kn = new HashMap<String, String>();
    HashMap<String, String> nk = new HashMap<String, String>();
    void reserve(String s1, String s2) { kn.put(s1, s2); }
    void rereserve(String s1, String s2) { nk.put(s1, s2); }

    void readch() throws IOException { peek = (char)System.in.read(); }
    boolean bl = true; 
    public String scan() throws IOException {
        for( ; ; readch()) {
            if( peek == '\t' || peek == ' ') continue;
            else if( peek == '\n' ) {
                readch();
                // print the answer 
                if( peek == '\n' ) {
                    return "exe";
                }
                break;
            }
            else break;
        }

        if ( Character.isDigit(peek) ) {
            int v = 0;
            do {
                v = 10*v + Character.digit(peek, 10); readch();
            } while ( Character.isDigit(peek) );
            return Integer.toString(v);
        }

        if ( Character.isLetter(peek) ) {
            StringBuffer b = new StringBuffer();
            do {
                b.append(peek); readch();
            } while( Character.isLetter(peek) );
            String s = b.toString(); return s;
        }

        String speek = Character.toString(peek);
        peek = ' ';
        return speek;

    }

    // parser 
    String look;
    String ans = "";   // put it into answer
    ArrayList<String> objlist = new ArrayList<>();
    ArrayList<String> symbolist = new ArrayList<>();
    String symbol; String obj;

    void move() throws IOException { look = scan(); }

    // Start !
    public void program() throws IOException {
         while (bl) {
            move(); 
            switch (look) {
                case "def":
                    // define a variable
                    move(); String variable = look;
                    move(); String number = look;
                    if (kn.containsKey(variable)) {
                        String oldn = kn.get(variable);
                        kn.replace(variable, number);
                        nk.remove(oldn);
                    }
                    reserve(variable, number);
                    rereserve(number, variable);
                    break;
                    
                case "calc":
                    // caculate
                    move(); String firstobj = look;

                    ans += firstobj;
                    objlist.add(firstobj);

                    move(); // expr
                    while (look.equals("+") || look.equals("-")) {

                        symbol = look; symbolist.add(symbol); ans += " "; ans += symbol;

                        move(); obj = look; objlist.add(obj); ans += " "; ans += obj;
                        move();
                        if ( look.equals("=") ) {
                            ans += " "; ans += "=";
                            caculate();
                            break;
                        }
                    }
                    objlist.clear(); symbolist.clear();
                    break;

                case "exe":
                    bl = false;

                case "clear":
                    kn.clear();
                    nk.clear();
                    break;

                default:
                    throw new Error("Invalid command");
            }
        }
        for (String answ : answer) {
            System.out.println(answ);
        }

    }

    void caculate() throws IOException {
        int total = 0;
        int count = -1;
        for (int i = 0; i < objlist.size(); i++) {
            String objs = objlist.get(i);

            if (!kn.containsKey(objs)) {
                // return unknown
                ans += " "; ans += "unknown";
                answer.add(ans);
                count = i;
                break;
            } else {
                String objnum = kn.get(objs);
                if( i == 0) {
                    // total = firstobj (at first)
                    total += Integer.parseInt(objnum);
                }
                else {
                    String op = symbolist.get(i-1);
                    if ( op.equals("+")) total += Integer.parseInt(objnum);
                    else if (op.equals("-")) total -= Integer.parseInt(objnum);
                }
            }
        }
        if (count == -1) {
            // do not have unknown(break)
            String anstotal = Integer.toString(total);
            String sanstotal = "unknown";
            if (nk.containsKey(anstotal)) { sanstotal = nk.get(anstotal); }
            ans += " "; ans += sanstotal;
            answer.add(ans);
            ans = "";
        }

    }

    public static void main(String[] args) throws IOException { 
        addingWords parser = new addingWords();
        parser.program();
    }

}
