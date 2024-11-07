
-- Script Lua para gerenciar o Mestre do Encantamento

function onTalkToEnchantmentMaster(player, npc)
    npc:say("Escolha o atributo para encantar: 1 para Defesa, 2 para Habilidade, 3 para Resistência, 4 para Crítico.", TALKTYPE_SAY)
    local escolha = player:chooseOption() -- Placeholder para escolha do jogador
    if escolha then
        player:applyEnchantment(escolha)
        npc:say("Encantamento aplicado com sucesso!", TALKTYPE_SAY)
    else
        npc:say("Opção inválida.", TALKTYPE_SAY)
    end
end
