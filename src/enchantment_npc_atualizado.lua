
-- Script Lua para interação de encantamento com NPC usando gemas específicas
local GEM_ID_100 = 5936  -- Gema com 100% de chance de sucesso
local GEM_ID_25 = 5934   -- Gema com 25% de chance de sucesso

function onTalkToEnchantmentMaster(player, npc, item)
    -- Verifica se o jogador está usando uma das gemas para encantar
    if item:getId() == GEM_ID_100 then
        npc:say("Encantamento garantido! Escolha seu atributo para encantar.", TALKTYPE_SAY)
    elseif item:getId() == GEM_ID_25 then
        local chance = math.random(100)
        if chance <= 25 then
            npc:say("Encantamento bem-sucedido! Escolha seu atributo para encantar.", TALKTYPE_SAY)
        else
            npc:say("Encantamento falhou. Tente novamente.", TALKTYPE_SAY)
            return
        end
    else
        npc:say("Este item não pode ser usado para encantamento.", TALKTYPE_SAY)
        return
    end

    -- Solicita ao jogador que escolha o atributo para encantar
    npc:say("Escolha: 1 para Defesa, 2 para Habilidade, 3 para Resistência, 4 para Crítico.", TALKTYPE_SAY)
    local escolha = player:chooseOption() -- Placeholder para escolha do jogador
    if escolha then
        player:applyEnchantment(escolha)
        npc:say("Encantamento aplicado com sucesso!", TALKTYPE_SAY)
    else
        npc:say("Opção inválida.", TALKTYPE_SAY)
    end
end
