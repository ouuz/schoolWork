/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class MagicMachine {

    public void useMachine(Person person) {
        person.increaseHeight(50);
        System.out.println("现在," + person.getName() + "的身高是:" + person.getHeight());
        System.out.println("太神奇了！");
    }
}
