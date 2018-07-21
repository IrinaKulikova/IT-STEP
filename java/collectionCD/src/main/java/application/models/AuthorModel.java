package application.models;

public class AuthorModel {
    int id;
    String name;
    String lastname;
    GenreModel genre;
    ContryModel contry;

    public AuthorModel(int id, String name, String lastname, GenreModel genre, ContryModel contry) {
        this.id = id;
        this.name = name;
        this.lastname = lastname;
        this.genre = genre;
        this.contry = contry;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public GenreModel getGenre() {
        return genre;
    }

    public void setGenre(GenreModel genre) {
        this.genre = genre;
    }

    public ContryModel getContry() {
        return contry;
    }

    public void setContry(ContryModel contry) {
        this.contry = contry;
    }
}
