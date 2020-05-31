/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ouu
 */
public class VIP {

    private String name, gender;
    private int height;

    public String getName() {
        return name;
    }

    public int getHeight() {
        return height;
    }

    public String getGender() {
        return gender;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public VIP(String name, String gender, int height) {
        this.gender = gender;
        this.height = height;
        this.name = name;
    }
}
