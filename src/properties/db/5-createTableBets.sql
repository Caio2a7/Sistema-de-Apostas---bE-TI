CREATE TABLE IF NOT EXISTS apostas (
    id SERIAL PRIMARY KEY,
    id_usuario INTEGER NOT NULL,
    id_evento INTEGER NOT NULL,
    valor NUMERIC(15, 2) NOT NULL,
    aposta VARCHAR(50) NOT NULL,
    FOREIGN KEY (id_usuario) REFERENCES usuario(id),
    FOREIGN KEY (id_evento) REFERENCES eventos(id)
);
