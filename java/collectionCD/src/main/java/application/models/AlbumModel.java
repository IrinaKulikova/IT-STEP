package application.models;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class AlbumModel {

    private int id;
    private AuthorModel author;
    private String name;
    private int tracks;

    public AlbumModel(int id, AuthorModel author, String name, int tracks) {
        this.id = id;
        this.author = author;
        this.name = name;
        this.tracks = tracks;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public AuthorModel getAuthor() {
        return author;
    }

    public void setAuthor(AuthorModel author) {
        this.author = author;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getTracks() {
        return tracks;
    }

    public void setTracks(int tracks) {
        this.tracks = tracks;
    }
}