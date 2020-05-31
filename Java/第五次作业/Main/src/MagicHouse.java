/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class MagicHouse {

    private Bread bread;
    private MagicMachine machine;

    public void enterHouse(Person person) {
        System.out.println("进入魔法屋前\n" + person.getName() + "的身高是:" + person.getHeight());
    }

    public Bread findBread(Person person) {
        System.out.println(person.getName() + "吃面包长高");
        return bread = new Bread();
    }

    public MagicMachine findMachine(Person person) {
        System.out.println("太慢了," + person.getName() + "尝试使用魔法机器");
        return machine = new MagicMachine();
    }
}
