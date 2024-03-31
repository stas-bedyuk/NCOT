
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

CREATE TABLE IF NOT EXISTS PhoneDirectory (
    id                      INTEGER PRIMARY KEY,
    phone                   varchar (256) NOT NULL,
    name                    varchar (256) NOT NULL,
    address                 varchar (256) NOT NULL
);

INSERT INTO PhoneDirectory
( id, phone, name, address) VALUES ( 0,'+375445794xxx', 'Stas', 'Minsk');

