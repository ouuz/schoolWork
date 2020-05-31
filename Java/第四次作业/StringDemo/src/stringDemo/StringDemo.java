/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package string;

/**
 *
 * @author ouu
 */
public class StringDemo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String palindrome = "hello1234";
        int len = palindrome.length();
        char[] tempCharArray = new char[len];
        char[] charArray = new char[len];
        for (int i = 0; i < len; i++) {
            tempCharArray[i] = palindrome.charAt(i);
        }
        for (int j = 0; j < len; j++) {
            if (Character.isLetter(tempCharArray[j])) {
                charArray[j] = Character.toUpperCase(tempCharArray[j]);
            }
            if (Character.isDigit(tempCharArray[j])) {
                charArray[j] = (char) ((int) (tempCharArray[j] + 1));
            }
        }
        String transPalindrome = new String(charArray);
        System.out.println(transPalindrome);
    }

}
