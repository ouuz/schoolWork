/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class Bread {

    public void eatBread(Person person, int number) {
        for (int i = 0; i < number; i++) {
            System.out.println(person.getName() + "吃了一片面包");
            person.increaseHeight(1);
            System.out.println("现在," + person.getName() + "的身高是:" + person.getHeight());
        }
    }
}
