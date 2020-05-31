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

    public static void main(String[] args) {
        VIP xiaozhang = new VIP("小张", "男生", 145);
        VIP xiaofang = new VIP("小芳", "女生", 130);
        Magicmachine magicmachine = new Magicmachine();
        System.out.println("##############################");
        System.out.println("魔法屋的故事续集1——VIP会员真不错");
        System.out.println("##############################");
        System.out.println("老板：欢迎光临魔法屋！");
        System.out.println("老板：同学，现在注册会员免费喔。。。");
        System.out.println("老板：走过路过，不要错过。。。");
        System.out.println("小芳：这不是霸王条款吗？");
        System.out.println("小张：为了圆梦，忍忍吧！反正咱们又不花钱！");
        System.out.println("魔法屋注册会员完成。。。");
        System.out.println("==========");
        System.out.println("进入魔法屋前：");
        System.out.println("小芳的身高是：" + xiaofang.getHeight() + "厘米");
        System.out.println("小张的身高是：" + xiaozhang.getHeight() + "厘米");
        System.out.println("==========");
        System.out.println("小芳使用魔法机器");
        System.out.println("******************************");
        magicmachine.vipUser(xiaofang);
        System.out.println("******************************");
        System.out.println("现在小芳的身高是" + xiaofang.getHeight() + "厘米");
        System.out.println("==========");
        System.out.println("小张使用魔法机器");
        System.out.println("******************************");
        magicmachine.vipUser(xiaozhang);
        System.out.println("******************************");
        System.out.println("现在小张的身高是" + xiaozhang.getHeight() + "厘米");
        System.out.println("==========");
        System.out.println("小芳：嘻。。。嘻嘻嘻。。。");
        System.out.println("小张：嘻。。。嘻嘻嘻。。。");
        System.out.println("老板：哈哈哈哈。。。。。。");
    }
}
