CREATE TABLE Genres (
    genre_id SERIAL PRIMARY KEY,
    genre_name VARCHAR(60) NOT NULL
);

CREATE TABLE Artists (
    artist_id SERIAL PRIMARY KEY,
    artist_name VARCHAR(60) NOT NULL
);

CREATE TABLE Artist_Genre (
    artist_id INT,
    genre_id INT,
    FOREIGN KEY (artist_id) REFERENCES Artists(artist_id) ON DELETE CASCADE,
    FOREIGN KEY (genre_id) REFERENCES Genres(genre_id) ON DELETE CASCADE,
    CONSTRAINT pk_artist_genre PRIMARY KEY (artist_id, genre_id)
);

CREATE TABLE Albums (
    album_id SERIAL PRIMARY KEY,
    album_name VARCHAR(60) NOT NULL,
    release_year INT,
    artists_list VARCHAR(255)
);

CREATE TABLE Album_Artist (
    album_id INT,
    artist_id INT,
    FOREIGN KEY (album_id) REFERENCES Albums(album_id) ON DELETE CASCADE,
    FOREIGN KEY (artist_id) REFERENCES Artists(artist_id) ON DELETE CASCADE,
    CONSTRAINT pk_album_artist PRIMARY KEY (album_id, artist_id)
);

CREATE TABLE Tracks (
    track_id SERIAL PRIMARY KEY,
    track_name VARCHAR(60) NOT NULL,
    duration INTERVAL NOT NULL,
    album_id INT,
    FOREIGN KEY (album_id) REFERENCES Albums(album_id) ON DELETE CASCADE
);

CREATE TABLE Compilations (
    compilation_id SERIAL PRIMARY KEY,
    compilation_name VARCHAR(60) NOT NULL,
    release_year INT
);

CREATE TABLE Compilation_Track (
    compilation_id INT,
    track_id INT,
    FOREIGN KEY (compilation_id) REFERENCES Compilations(compilation_id) ON DELETE CASCADE,
    FOREIGN KEY (track_id) REFERENCES Tracks(track_id) ON DELETE CASCADE,
    CONSTRAINT pk_compilation_track PRIMARY KEY (compilation_id, track_id)
);