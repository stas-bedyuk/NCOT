
#ifndef EXAMPLE_POSTGRESQL_USERDB_HPP
#define EXAMPLE_POSTGRESQL_USERDB_HPP

#include "dto/UserDto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * UserDb client definitions.
 */
class UserDb : public oatpp::orm::DbClient {
public:

  UserDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

    oatpp::orm::SchemaMigration migration(executor);
    migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/001_init.sql");
    // TODO - Add more migrations here.
    migration.migrate(); // <-- run migrations. This guy will throw on error.

    auto version = executor->getSchemaVersion();
    OATPP_LOGD("UserDb", "Migration - OK. Version=%d.", version);

  }

  QUERY(createUser,
        "INSERT INTO phonedirectory"
        "(id, phone, name, address) VALUES "
        "(:user.id, :user.phone, :user.name, :user.address)"
        "RETURNING *;",
        PREPARE(true), // user prepared statement!
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(updateUser,
        "UPDATE phonedirectory "
        "SET "
        " phone=:user.phone, "
        " name=:user.name, "
        " address=:user.address "
        "WHERE "
        " id=:user.id "
        "RETURNING *;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(getUserById,
        "SELECT * FROM phonedirectory WHERE id=:id;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::Int32, id))

  QUERY(getAllUsers,
        "SELECT * FROM phonedirectory LIMIT :limit OFFSET :offset;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteUserById,
        "DELETE FROM phonedirectory WHERE id=:id;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::Int32, id))

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //EXAMPLE_POSTGRESQL_USERDB_HPP
