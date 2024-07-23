CREATE TABLE IF NOT EXISTS eventos (
    id SERIAL PRIMARY KEY,
    id_esporte INTEGER NOT NULL,
    id_time_a INTEGER NOT NULL,
    id_time_b INTEGER NOT NULL,
    odds DECIMAL(10,2)[] NOT NULL,
    horario TIMESTAMP NOT NULL,
    FOREIGN KEY (id_time_a) REFERENCES participantes(id),
    FOREIGN KEY (id_time_b) REFERENCES participantes(id),
    FOREIGN KEY (id_esporte) REFERENCES esporte(id)
);