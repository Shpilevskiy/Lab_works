package Stationery;

public class Stationery {
    public String country;
    public String firm;
    public String type;
    public String purpose;
    public String material;
    public int price;

    public Stationery() {
        this.country = "";
        this.firm = "";
        this.type = "";
        this.purpose = "";
        this.material = "";
        this.price = 0;
    }

    public Stationery(String country, String firm, String type, String purpose, String material, int price ) {
        this.country = country;
        this.firm = firm;
        this.type = type;
        this.purpose = purpose;
        this.material = material;
        this.price = price;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public void setFirm(String firm) {
        this.firm = firm;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setPurpose(String purpose) {
        this.purpose = purpose;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    public void setPrice (int price) {
        this.price = price;
    }



    public String getСountry(){return this.country;}

    public String getFirm(){return this.firm;}

    public String getType(){return this.type;}

    public String getPurpose(){return this.purpose;}

    public String getMaterial(){return this.material;}

    public int getPrice(){return this.price;}



    @Override
    public String toString() {
        return "------------------------\n" +
                "Страна: " + country + '\n' +
                "Фирма: " + firm + '\n' +
                "Тип: " + type + '\n' +
                "Назначение: " + purpose + '\n' +
                "Материал: " + material + '\n' +
                "Цена: " + price +
                "\n------------------------\n";
    }
}
