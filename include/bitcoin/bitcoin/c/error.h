/**
 * Copyright (c) 2011-2016 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_C_ERROR_H
#define LIBBITCOIN_C_ERROR_H

#include <stdbool.h>
#include <bitcoin/bitcoin/c/utility/string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum bc_console_result_t
{
    bc_console_result__failure = -1,
    bc_console_result__okay = 0,
    bc_console_result__invalid = 1

} bc_console_result_t;

// The numeric values of these codes may change without notice.
typedef enum bc_error_t
{
    // general codes
    bc_error__success = 0,
    bc_error__deprecated = 6,
    bc_error__unknown = 43,
    bc_error__not_found = 3,
    bc_error__file_system = 42,
    bc_error__non_standard = 17,
    bc_error__not_implemented = 4,
    bc_error__oversubscribed = 71,

    // network
    bc_error__service_stopped = 1,
    bc_error__operation_failed = 2,
    bc_error__resolve_failed = 7,
    bc_error__network_unreachable = 8,
    bc_error__address_in_use = 9,
    bc_error__listen_failed = 10,
    bc_error__accept_failed = 11,
    bc_error__bad_stream = 12,
    bc_error__channel_timeout = 13,
    bc_error__address_blocked = 44,
    bc_error__channel_stopped = 45,

    // database
    bc_error__store_block_duplicate = 66,
    bc_error__store_block_invalid_height = 67,
    bc_error__store_block_missing_parent = 68,

    // block pool
    bc_error__duplicate_block = 51,
    bc_error__orphan_block = 5,
    bc_error__invalid_previous_block = 24,
    bc_error__insufficient_work = 48,

    // transaction pool
    bc_error__orphan_transaction = 14,
    bc_error__insufficient_fee = 70,

    // check header
    bc_error__invalid_proof_of_work = 26,
    bc_error__futuristic_timestamp = 27,

    // accept header
    bc_error__checkpoints_failed = 35,
    bc_error__old_version_block = 36,
    bc_error__incorrect_proof_of_work = 32,
    bc_error__timestamp_too_early = 33,

    // check block
    bc_error__block_size_limit = 50,
    bc_error__empty_block = 47,
    bc_error__first_not_coinbase = 28,
    bc_error__extra_coinbases = 29,
    bc_error__internal_duplicate = 49,
    bc_error__block_internal_double_spend = 15,
    bc_error__transaction_internal_double_spend = 72,
    bc_error__merkle_mismatch = 31,
    bc_error__block_legacy_sigop_limit = 30,

    // accept block
    bc_error__transaction_non_final = 34,
    bc_error__coinbase_height_mismatch = 37,
    bc_error__coinbase_value_limit = 41,
    bc_error__block_embedded_sigop_limit = 52,

    // check transaction
    bc_error__empty_transaction = 20,
    bc_error__previous_output_null = 23,
    bc_error__spend_overflow = 21,
    bc_error__invalid_coinbase_script_size = 22,
    bc_error__coinbase_transaction = 16,
    bc_error__transaction_size_limit = 53,
    bc_error__transaction_legacy_sigop_limit = 54,

    // accept transaction
    bc_error__premature_validation = 69,
    bc_error__unspent_duplicate = 38,
    bc_error__missing_previous_output = 19,
    bc_error__double_spend = 18,
    bc_error__coinbase_maturity = 46,
    bc_error__spend_exceeds_value = 40,
    bc_error__transaction_embedded_sigop_limit = 55,

    // connect input
    bc_error__invalid_script = 39,
    bc_error__invalid_script_size = 56,
    bc_error__invalid_push_data_size = 57,
    bc_error__invalid_operation_count = 58,
    bc_error__invalid_stack_size = 59,
    bc_error__invalid_stack_scope = 60,
    bc_error__invalid_script_embed = 61,
    bc_error__invalid_signature_encoding = 62,
    bc_error__invalid_signature_lax_encoding = 63,
    bc_error__incorrect_signature = 64,
    bc_error__stack_false = 65,

    // op eval
    bc_error__op_disabled = 100,
    bc_error__op_reserved,
    bc_error__op_push_size,
    bc_error__op_push_data,
    bc_error__op_if,
    bc_error__op_notif,
    bc_error__op_else,
    bc_error__op_endif,
    bc_error__op_verify1,
    bc_error__op_verify2,
    bc_error__op_return,
    bc_error__op_to_alt_stack,
    bc_error__op_from_alt_stack,
    bc_error__op_drop2,
    bc_error__op_dup2,
    bc_error__op_dup3,
    bc_error__op_over2,
    bc_error__op_rot2,
    bc_error__op_swap2,
    bc_error__op_if_dup,
    bc_error__op_drop,
    bc_error__op_dup,
    bc_error__op_nip,
    bc_error__op_over,
    bc_error__op_pick,
    bc_error__op_roll,
    bc_error__op_rot,
    bc_error__op_swap,
    bc_error__op_tuck,
    bc_error__op_size,
    bc_error__op_equal,
    bc_error__op_equal_verify1,
    bc_error__op_equal_verify2,
    bc_error__op_add1,
    bc_error__op_sub1,
    bc_error__op_negate,
    bc_error__op_abs,
    bc_error__op_not,
    bc_error__op_nonzero,
    bc_error__op_add,
    bc_error__op_sub,
    bc_error__op_bool_and,
    bc_error__op_bool_or,
    bc_error__op_num_equal,
    bc_error__op_num_equal_verify1,
    bc_error__op_num_equal_verify2,
    bc_error__op_num_not_equal,
    bc_error__op_less_than,
    bc_error__op_greater_than,
    bc_error__op_less_than_or_equal,
    bc_error__op_greater_than_or_equal,
    bc_error__op_min,
    bc_error__op_max,
    bc_error__op_within,
    bc_error__op_ripemd160,
    bc_error__op_sha1,
    bc_error__op_sha256,
    bc_error__op_hash160,
    bc_error__op_hash256,
    bc_error__op_code_seperator,
    bc_error__op_check_sig_verify1,
    bc_error__op_check_sig,
    bc_error__op_check_multisig_verify1,
    bc_error__op_check_multisig_verify2,
    bc_error__op_check_multisig_verify3,
    bc_error__op_check_multisig_verify4,
    bc_error__op_check_multisig_verify5,
    bc_error__op_check_multisig_verify6,
    bc_error__op_check_multisig_verify7,
    bc_error__op_check_multisig,
    bc_error__op_check_locktime_verify1,
    bc_error__op_check_locktime_verify2,
    bc_error__op_check_locktime_verify3,
    bc_error__op_check_locktime_verify4,
    bc_error__op_check_locktime_verify5,
    bc_error__op_check_locktime_verify6

} bc_error_t;

typedef struct bc_error_code_t bc_error_code_t;
bc_error_code_t* bc_create_error_code(bc_error_t error);
bc_error_code_t* bc_create_error_code_default();
void bc_destroy_error_code(bc_error_code_t* self);
bc_string_t* bc_error_code__message(const bc_error_code_t* self);
bool bc_error_code__is_valid(const bc_error_code_t* self);
bool bc_error_code__equals(const bc_error_code_t* self, bc_error_t ec);

#ifdef __cplusplus
}
#endif

#endif

