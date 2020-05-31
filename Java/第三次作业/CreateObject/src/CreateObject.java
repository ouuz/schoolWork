/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class CreateObject {
        public static void main(String[] args){
        Point origin_one = new Point(23,94);
        Rectangle rect_one = new Rectangle(origin_one, 100, 200);
        Rectangle rect_two = new Rectangle(50,100);
        System.out.println("Width of rect_one: " + rect_one.getwidth());
        System.out.println("Height of rect_one: " + rect_one.getheight());
        System.out.println("Area of rect_one: " + rect_one.area());

        rect_two.origin = origin_one;
        System.out.println("X Position of rect_two: " + rect_two.origin.getx());
        System.out.println("Y Position of rect_two: " + rect_two.origin.gety());

        rect_two.move(40, 72);
        System.out.println("X Position of rect_two: " + rect_two.origin.getx());
        System.out.println("y Position of rect_two: " + rect_two.origin.gety());
    }
}
