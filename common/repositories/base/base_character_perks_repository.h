/**
 * DO NOT MODIFY THIS FILE
 *
 * This repository was automatically generated and is NOT to be modified directly.
 * Any repository modifications are meant to be made to the repository extending the base.
 * Any modifications to base repositories are to be made by the generator only
 *
 * @generator ./utils/scripts/generators/repository-generator.pl
 * @docs https://docs.eqemu.io/developer/repositories
 */

#ifndef EQEMU_BASE_CHARACTER_PERKS_REPOSITORY_H
#define EQEMU_BASE_CHARACTER_PERKS_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>

class BaseCharacterPerksRepository {
public:
	struct CharacterPerks {
		int32_t id_char;
		int32_t id_perk;
		int8_t  perk_rank;
		int8_t  enabled;
	};

	static std::string PrimaryKey()
	{
		return std::string("id_char");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id_char",
			"id_perk",
			"perk_rank",
			"enabled",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"id_char",
			"id_perk",
			"perk_rank",
			"enabled",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(Strings::Implode(", ", Columns()));
	}

	static std::string SelectColumnsRaw()
	{
		return std::string(Strings::Implode(", ", SelectColumns()));
	}

	static std::string TableName()
	{
		return std::string("character_perks");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			SelectColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static CharacterPerks NewEntity()
	{
		CharacterPerks e{};

		e.id_char   = 0;
		e.id_perk   = 0;
		e.perk_rank = 0;
		e.enabled   = 0;

		return e;
	}

	static CharacterPerks GetCharacterPerks(
		const std::vector<CharacterPerks> &character_perkss,
		int character_perks_id
	)
	{
		for (auto &character_perks : character_perkss) {
			if (character_perks.id_char == character_perks_id) {
				return character_perks;
			}
		}

		return NewEntity();
	}

	static CharacterPerks FindOne(
		Database& db,
		int character_perks_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {} = {} LIMIT 1",
				BaseSelect(),
				PrimaryKey(),
				character_perks_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			CharacterPerks e{};

			e.id_char   = row[0] ? static_cast<int32_t>(atoi(row[0])) : 0;
			e.id_perk   = row[1] ? static_cast<int32_t>(atoi(row[1])) : 0;
			e.perk_rank = row[2] ? static_cast<int8_t>(atoi(row[2])) : 0;
			e.enabled   = row[3] ? static_cast<int8_t>(atoi(row[3])) : 0;

			return e;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int character_perks_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				character_perks_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		const CharacterPerks &e
	)
	{
		std::vector<std::string> v;

		auto columns = Columns();

		v.push_back(columns[0] + " = " + std::to_string(e.id_char));
		v.push_back(columns[1] + " = " + std::to_string(e.id_perk));
		v.push_back(columns[2] + " = " + std::to_string(e.perk_rank));
		v.push_back(columns[3] + " = " + std::to_string(e.enabled));

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", v),
				PrimaryKey(),
				e.id_char
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static CharacterPerks InsertOne(
		Database& db,
		CharacterPerks e
	)
	{
		std::vector<std::string> v;

		v.push_back(std::to_string(e.id_char));
		v.push_back(std::to_string(e.id_perk));
		v.push_back(std::to_string(e.perk_rank));
		v.push_back(std::to_string(e.enabled));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", v)
			)
		);

		if (results.Success()) {
			e.id_char = results.LastInsertedID();
			return e;
		}

		e = NewEntity();

		return e;
	}

	static int InsertMany(
		Database& db,
		const std::vector<CharacterPerks> &entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &e: entries) {
			std::vector<std::string> v;

			v.push_back(std::to_string(e.id_char));
			v.push_back(std::to_string(e.id_perk));
			v.push_back(std::to_string(e.perk_rank));
			v.push_back(std::to_string(e.enabled));

			insert_chunks.push_back("(" + Strings::Implode(",", v) + ")");
		}

		std::vector<std::string> v;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				Strings::Implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<CharacterPerks> All(Database& db)
	{
		std::vector<CharacterPerks> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			CharacterPerks e{};

			e.id_char   = row[0] ? static_cast<int32_t>(atoi(row[0])) : 0;
			e.id_perk   = row[1] ? static_cast<int32_t>(atoi(row[1])) : 0;
			e.perk_rank = row[2] ? static_cast<int8_t>(atoi(row[2])) : 0;
			e.enabled   = row[3] ? static_cast<int8_t>(atoi(row[3])) : 0;

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static std::vector<CharacterPerks> GetWhere(Database& db, const std::string &where_filter)
	{
		std::vector<CharacterPerks> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			CharacterPerks e{};

			e.id_char   = row[0] ? static_cast<int32_t>(atoi(row[0])) : 0;
			e.id_perk   = row[1] ? static_cast<int32_t>(atoi(row[1])) : 0;
			e.perk_rank = row[2] ? static_cast<int8_t>(atoi(row[2])) : 0;
			e.enabled   = row[3] ? static_cast<int8_t>(atoi(row[3])) : 0;

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static int DeleteWhere(Database& db, const std::string &where_filter)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {}",
				TableName(),
				where_filter
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int Truncate(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"TRUNCATE TABLE {}",
				TableName()
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int64 GetMaxId(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COALESCE(MAX({}), 0) FROM {}",
				PrimaryKey(),
				TableName()
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

	static int64 Count(Database& db, const std::string &where_filter = "")
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COUNT(*) FROM {} {}",
				TableName(),
				(where_filter.empty() ? "" : "WHERE " + where_filter)
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

	static std::string BaseReplace()
	{
		return fmt::format(
			"REPLACE INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static int ReplaceOne(
		Database& db,
		const CharacterPerks &e
	)
	{
		std::vector<std::string> v;

		v.push_back(std::to_string(e.id_char));
		v.push_back(std::to_string(e.id_perk));
		v.push_back(std::to_string(e.perk_rank));
		v.push_back(std::to_string(e.enabled));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseReplace(),
				Strings::Implode(",", v)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int ReplaceMany(
		Database& db,
		const std::vector<CharacterPerks> &entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &e: entries) {
			std::vector<std::string> v;

			v.push_back(std::to_string(e.id_char));
			v.push_back(std::to_string(e.id_perk));
			v.push_back(std::to_string(e.perk_rank));
			v.push_back(std::to_string(e.enabled));

			insert_chunks.push_back("(" + Strings::Implode(",", v) + ")");
		}

		std::vector<std::string> v;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseReplace(),
				Strings::Implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}
};

#endif //EQEMU_BASE_CHARACTER_PERKS_REPOSITORY_H
