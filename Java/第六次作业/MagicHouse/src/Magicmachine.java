/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class Magicmachine implements MagicHousevip {

    public void vipUser(VIP t) {
        System.out.println("魔法机器：尊敬的客人，感谢您体验魔法机器");
        if (t.getGender().equals("男生")) {
            System.out.println("魔法机器：机器识别出您是" + t.getGender());
            System.out.println("魔法机器：机器将使您增高40厘米");
            t.setHeight(t.getHeight() + 40);
        } else {
            System.out.println("魔法机器：机器识别出您是" + t.getGender());
            System.out.println("魔法机器：机器将使您增高30厘米");
            t.setHeight(t.getHeight() + 30);
        }
    }
}
