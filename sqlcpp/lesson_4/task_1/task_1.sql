insert into artists (artist_name) values ('Linkin Park'), ('Metallica'), ('Megadeth'), ('Fall Out Boy'), ('СЛОТ');

insert into genres (genre_name) values ('поп-панк'), ('поп-рок'), ('хеви-метал'), ('трэш-метал'), ('хард-рок'), ('альтернативный-рок');

insert into albums (album_name, release_year) values ('Save Rock And Roll', 2013), ('Kill ''Em All', 1983), ('Meteora', 2003);

insert into tracks (track_name, duration, album_id) values ('Hit The Light', '4:15', 2), ('Jump In The Fire', '4:41', 2), ('My Songs Know What You Did In The Dark (Light Em Up', '3:06', 1),('Hit the Floor', '2:44', 3),('Breaking the Habit', '3:16', 3),('Numb', '3:07', 3);

insert into compilations (compilation_name, release_year) values ('Fast', 2016), ('Good', 2018), ('What', 2019);

insert into artist_genre (artist_id, genre_id) values (1, 6), (1, 2), (2, 4), (3, 4), (4, 1), (4, 2);

insert into compilation_track (compilation_id, track_id) values (1, 1), (1, 2), (2, 1), (2, 2), (2, 4), (3, 3), (3, 5);

insert into album_artist (album_id, artist_id) values (1, 4), (2, 2), (3, 1);