/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class Magichouse {

    public static void main(String[] args) {
        Measuresvip XiaoMing = new Measuresvip(192, 0);
        MagicMachine magicmachine = new MagicMachine();
        System.out.println("##############################");
        System.out.println("魔法屋的故事续集2——魔法机器里的惊魂一刻");
        System.out.println("##############################");
        System.out.println("老板：欢迎光临魔法屋！");
        System.out.println("老板：好久不见，有什么能帮您的吗？");
        System.out.println("小明：我想要变矮一点点，请问你们提供变矮服务吗？");
        System.out.println("老板：您真幸运，我们刚推出了超级VIP会员！");
        System.out.println("老板：超级VIP会员，可变高，可变矮，任君选择。");
        System.out.println("老板：注册就送50元账户充值红包两个");
        System.out.println("小明：变矮多少钱？");
        System.out.println("老板：高矮一个价：男生每厘米10元，女生每厘米5元");
        System.out.println("小明：有点贵啊，试试吧，反正送了100元！我就减10厘米！");
        System.out.println("==========");
        System.out.println("进入魔法屋前：");
        System.out.println("小明的身高是：" + XiaoMing.height);
        System.out.println("==========");
        System.out.println("小明使用魔法机器。。。");
        System.out.println("*******************");
        magicmachine.svipUser(XiaoMing);
        System.out.println("==========");
        System.out.println("紧急呼叫老板，魔法机器里面卡人了。。。");
        System.out.println("小明：救命啊！！！！！！！！我被卡在机器里了！！！");
        System.out.println("==========");
        System.out.println("老板打开机器，把小明拽了出来。");
        System.out.println("小明：吓死我了，什么破机器啊这是。");
        System.out.println("老板拿出尺子量了量，小明的身高是" + XiaoMing.height + "厘米");
        System.out.println("老板：幸好身高没变，实在是抱歉。。。");
        System.out.println("老板：麻烦您查看一下账户余额，谢谢");
        System.out.println("小明：好。");
        System.out.println("账户余额：" + XiaoMing.money + "元");
        System.out.println("老板：啊，没钱你变个啥啊？");
        System.out.println("小明：哦，我忘记把红包充值进去了。。。");
        System.out.println("老板：原来是这样，不好意思，让您受惊了。");
        System.out.println("老板：为了表示我们的歉意，我在送你5个50元红包吧。");
        System.out.println("老板：这次不要再忘充值了啊。");
        System.out.println("小明：谢谢老板。。。");
        System.out.println("小明往SVIP账户上充值了350元。。。");
        XiaoMing.money = XiaoMing.money + 350;
        System.out.println("==========");
        System.out.println("小明使用魔法机器。。。");
        System.out.println("*******************");
        magicmachine.svipUser(XiaoMing);
        System.out.println("*******************");
        System.out.println("现在，小明的身高是：" + XiaoMing.height + "厘米");
        System.out.println("==========");
        System.out.println("小明查看账户。");
        System.out.println("账户余额" + XiaoMing.money + "元");
        System.out.println("小明：哈哈哈。。。今天真是太开心了，还赚了" + XiaoMing.money + "元");
        System.out.println("老板：欢迎下次光临。不要忘了多介绍几个同学来啊，我给打折。");
        System.out.println("哈哈哈哈。。。。。。");
    }
}
