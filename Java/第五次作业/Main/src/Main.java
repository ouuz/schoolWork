/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class Main {

    public static void main(String[] args) {
        Person person = new Person("小明", 140);
        MagicHouse magicHouse = new MagicHouse();
        magicHouse.enterHouse(person);
        System.out.println("==========");
        magicHouse.findBread(person).eatBread(person, 2);
        System.out.println("==========");
        magicHouse.findMachine(person).useMachine(person);
    }
}
