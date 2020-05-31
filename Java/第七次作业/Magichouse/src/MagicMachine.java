/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class MagicMachine implements MagicHousesvip {

    public void magicMachine(Measure XiaoMing) {
        XiaoMing.height = XiaoMing.height + 50;
        System.out.println("最后小明的身高超过了" + XiaoMing.height + "厘米");
    }

    public void svipUser(Measuresvip XiaoMing) {
        System.out.println("魔法机器：尊敬的超级VIP，感谢您体验魔法机器");
        System.out.println("超级VIP可以享受定制的增高或降低服务");
        System.out.println("本次服务将收取费用：100元");
        if (XiaoMing.money < 100) {
            System.out.println("错误：账户余额不足，机器停止工作");
        } else {
            System.out.println("魔法机器：机器检测出您是男生");
            System.out.println("魔法机器：机器将使您降低10厘米");
            XiaoMing.money = XiaoMing.money - 100;
            XiaoMing.height = XiaoMing.height - 10;
        }
    }
}
