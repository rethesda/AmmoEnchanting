#pragma once

#include "Ext/EnchantConstructMenu.h"

namespace Hooks
{
	class FilterFlags
	{
	public:
		using FilterFlag = Ext::EnchantConstructMenu::FilterFlag;
		using Menu = RE::CraftingSubMenus::EnchantConstructMenu;

		FilterFlags() = delete;

		static void Install();

	private:
		// Set up category filters in EnchantConstructMenu
		static void ConstructorPatch();
		// Allow Ammo forms to be added to entry list and assign EnchantAmmo flag
		static void EnchantEntryPatch();
		// Assign DisenchantAmmo flag for enchanted ammo
		static void DisenchantEntryPatch();
		// Assign EffectAmmo flag for base ammo enchantments
		static void EffectEntryPatch();
		// Learn effect when selecting DisenchantAmmo entries
		static void DisenchantSelectPatch();
		// Enable DisenchantAmmo entries
		static void DisenchantEnablePatch();
		//
		static void DisenchantLearnPatch();
		// Correct button text for DisenchantAmmo
		static void ButtonTextPatch();
		//
		static void CanSelectEntryPatch();
		// Handle Ammo flags when selecting an entry
		static void SelectEntryPatch();
		// When selecting an enchantment without an item, identify Ammo form type
		static void ItemPreviewPatch();

		static void PushBack(void* a_arg1, Menu::EnchantmentEntry* a_entry);

		static std::uint32_t GetEnabledFilters(Menu::Selections* a_selected);

		static RE::FormType GetFormTypeFromEffectFlag(std::uint32_t a_flag);

		inline static REL::Relocation<decltype(&PushBack)> _PushBack;
	};
}
