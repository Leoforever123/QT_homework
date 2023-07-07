
#include "dialogue.h"

dialogue::dialogue()
{

}
QString dialogue::map_str[42]={"铁匠：小伙子！今天是你成年的日子！你该拿起武器保护自己和自己热爱的事物了！这把长剑我刚打造好，试试看顺不顺手！"
                                 ,"铁匠：打铁还需自身硬！想和我一起打铁吗？"
                                 ,"魔女：你身上似乎有种强大的力量，你小时候就这样……这颗药丸就送给你了，吃了它可以激发你的魔法天赋。\n魔女：还有这个魔法秘籍，里面的魔法对你有用，千万别忘记！"
                                 ,"魔女：你的魔力令人恐惧......"
                                 ,"商人：我每个月都到大陆上看看，Oliver。到外面看看可以增长你的见识。"
                                 ,"渔夫：你知道吗，每个出海的人都渴望冒险。孩子，你不想去海上看看吗？"
                                 ,"奶奶:孩子，在大家的照顾下你终于长大啦，变成一个英俊的小伙子啦，你的样子总让我想起300年前那场大战中的英雄，说起他，那叫一个英俊潇洒……\n Oliver:奶奶，这个故事我已经听你讲了无数遍啦！耳朵都长茧了！\nOliver:您好好歇着啊，我还有急事！"
                                 ,"奶奶:想听英雄的故事吗？\n Oliver:不了奶奶，还有急事！\n奶奶:整整300年过去了。\n奶奶：当年那个英雄和魔王大战了三百回合，打的昏天黑地。\n奶奶：最后，主角用生命的代价彻底击垮了魔王\n奶奶：英雄的手下把魔王的追随者都驱逐到了放逐之地……\n Oliver:再见了奶奶。\n奶奶:(微笑)再见，小英雄。"
                                 ,"疯子：魔王万岁！\n（主角内心os：真想揍扁他！）"
                                 ,"吃一块糖吧！下次给我带点玩具^-^"
                                 ,"神兽：你太瘦弱了！这里的风会把你吹垮！"
                                 ,"神兽：前方的大门冻的很结实，你进不去！"
                                 ,"      神兽：神器现世，此门当开！"
                                 ,""
                                 ,""
                                 ,""
                                 ,""
                                 ,""
                                 ,""
                                 ,""
                                 ,"箱子中的鬼魂：看样子你是外来的法师吧！估计已经很多年过去了！如今的魔法大不如前了。你看到这些话语的时候，我早已过世了。我给你留下了一样好东西，据说是两个神明大战留下来的。至于密码，你自己想办法吧！给你一个提示，永恒的事物。若你有缘，自然能得到它。"
                                 ,"箱子中的鬼魂：看样子你真的是有缘之人。这把剑奥妙无穷。若你想用魔法催动这把剑，你会感受被强大的意识所注视的恐惧。只有神才能掌控这把剑的全部力量。请你不要滥用这把剑的力量。切记！"
                                 ,"箱子中的鬼魂：看来你还得再想想。"
                                 ,"箱子中的鬼魂：别想在我这在找到什么好东西了。如你所见，我已经空了！"
                                 ,""
                                 ,""
                                 ,""
                                 ,""
                                 ,""
                                 ,""
                                 ,"Oliver看到Fessor正在从一个活人身上放血。那个人十分痛苦，看样子已经救不活了。Oliver快步走上前\nOliver:你在干什么？！\nFessor(一个残暴而嗜血的法师):你来这里意欲何为？我能感受到你的魔力与我们的不同。\nFessor:赶紧离开这里，否则别怪我们把你杀了！\n"
                                 ,"Oliver:你们以前也是这么对待来访者的么?\nFessor:怎么，来的人我们都是直接杀掉的。\nFessor:因为我们需要祭品，需要魔力，祭品的灵魂也会被我们利用。\nFessor:有时我们还得到大陆上寻找猎物呢。你想怎么样？\n"
                                 ,"Oliver:看来传言所说的没错。你们这些为了追求所谓的力量而不择手段的人类,随意杀害自己的同伴，已经无可救药了。\nOliver施展了灼烧。\nFessor用魔力聚集抵挡，但这是徒劳的，Oliver的魔法过于强大。Fessor发出了惨叫，他整个人都感受着剧烈的疼痛。Fessor被活活烧成了灰烬\nOliver:这是你应得的。\n"
                                 ,"许多人涌了过来。其中一个高呼道：你是谁？\nOliver:我是Oliver.你是？\nSatan:我叫Satan.你为何把Fessor杀了？\nOliver:他犯下了不可饶恕的罪过。没有摧毁他的灵魂已经是我的仁慈了。\nSatan:你又是什么多管闲事的人？你不知道这是与整个放逐之地为敌吗？"
                                 ,"Oliver:那又如何？我不在乎你们。\nSatan:这里聚集着许多所谓的罪犯与被流放的法师，我们只遵循弱肉强食的法则。\nSatan:在这里，生命的消失再正常不过。\nSatan:所以你杀了Fessor,但是我和他没什么交情，这也无所谓。\nSatan:如果你想加入我们，那再好不过。\nSatan:但如果你想向我们挑衅，那我们就没什么好说的了。"
                                 ,"Oliver:听说你们都有信仰？\nSatan:随你怎么说。我们只认可力量。但这里的确住着许多自称追随一个强大神明的人。\nSatan:包括那个Fessor,这个人简直是个怪人,也是个疯子，每天嘟囔着什么祭品。\nSatan:像我就单纯多了......你到底加不加入我们？\nSatan:如果不，你绝对别想离开。只有死人才不会泄漏秘密。\nOliver:和你们这种东西为伍令我恶心。\nSatan:你竟敢骂我？看我怎么对付你！"
                                 ,"Satan用一种附带着精神冲击的黑暗魔法攻击了Oliver。但Oliver的灵魂过于强大，只受到了轻微的冲击。不知为何，Oliver又似乎想起了什么。Oliver挥出一剑，直接斩杀了Satan,灵魂也消散了。其余的人大多惊恐地看向Oliver,然后四散奔逃。因为他们知道Fessor与Satan都是强大的法师，却如此轻松就被Oliver击败。"
                                 ,"但有些人却显示出诡异的表情。\n'我伟大的神，谨以我的血肉帮助您的回归！',Oliver没有来得及惊讶，这些人就纷纷跳入了一个隐藏得很好的魔法阵。此刻这个魔法阵亮了起来，而Oliver控制不住自己精神世界传来的强烈波动......在一阵奇异的声响后，魔法阵又逐渐暗了下去，而跳进去的人却都消失不见。黑暗中，一个高大魁梧的生物出现了。看到它之后，Oliver似乎想起了什么，祂感知到了海量的信息。似乎有什么东西消失了。"
                                 ,"Feardorchae:（惊讶了一下，但随后恢复镇定）你认识我的，Oliver。我还记得你。\nOliver:（在被海量信息冲击过后）我也记得你，Feardorchae。好久不见。想不到你如今恢复的这么好了。\nFeardorchae:（冷笑）承蒙你的关照，Oliver。上次你见到我还是...我想不起来了。不过你如今可是变了样子，竟然化成一个人类。\nOliver:还不是因为你的魔法，弄得我当时差点就死了。\nFeardorchae:......难道不是你把我打的只能逃跑了？\nOliver:你胡做非为，肆意伤害生灵，上次你打到我的居所，把我的许多人类朋友杀了，我才如此愤怒。\nOliver:如今你又搞了些什么？这些人的信仰恐怕只能是你吧！\nOliver:另外你曾经害过我，那次我差点就死了，我恢复了很久，你忘记了？\nFeardorchae:(轻笑)是我，但这也并非全都是我的过错。我并没害你，那算是个意外。另外，我们同为神明，为何你总在乎那些蝼蚁？\nOliver:所有的生灵都不应被蔑视。为何你的魔力沾染了如此多关于杀戮的气息,Feardorchae。你该停手了，我可以不摧毁你的灵魂。Feardorchae:我的确杀了不少。为什么你总想让我反思，Oliver?最近我简直控制不住我自己。在这里躲了这么久......\nOliver:你知道我为何而来。不用再聊那些了。\nOliver:我的良知不容许我看到世上的生灵被如此残害，我将给予你应有的惩罚，Feardorchae。\nFeardorchae:你太固执了，Oliver。\n"
                                 ,"经过激烈的战斗，Feardorchae身上伤痕累累，魔力也消耗了许多。Feardorchae竭尽全力维持着目前的形态。Feardorchae:你竟然如此强大,Oliver。看来我低估了你。\nFeardorchae:（挣扎着）看来我的灵魂是摆脱不了毁灭的命运了。也罢，我早就想到总有这一天。就算没有你，也有别的神明......\nFeardorchae闭上了双眼。\nOliver:（情绪略有波动）那我将给予你我最后的尊重。\nOliver举起了火焰剑，这是附上灵魂灼烧法术的全力一击，带着神明的全部力量......\n"
                                 ,"经过激烈的战斗，Oliver与Feardorchae都伤痕累累，魔力也几乎消耗殆尽了。目力所及几乎全是战斗后的焦土。Feardorchae:你的情绪太不稳定了，Oliver。有什么东西影响了你。Oliver:(感受到了什么，却下意识地反驳)并没有，Feardorchae。我再问你一次。你忏悔么？Feardorchae:你的精神力量不够强，Oliver。你被这里的气息影响了。这会让你只想着杀戮。\nOliver:(已经无法控制自己)我....（缓慢举起火焰剑）\nFeardorchae:(喘着气)你不要那样做。被这里气息影响的攻击会耗费额外的魔力，好似燃烧你的灵体。这样下去你会死的。\nOliver:这还不是因为你......我......\n"
                                 ,"经过战斗，Feardorchae的魔力消耗了许多，但仍足以抵挡Oliver源源不断的魔法攻击。Oliver也逐渐支撑不住，不得不停止了魔法的释放。\nFeardorchae:你杀不死我,Oliver。别再那么固执了。\nFeardorchae:你的情绪太不稳定了，Oliver。有什么东西影响了你。Oliver:(感受到了什么，却下意识地反驳)并没有，Feardorchae。我再问你一次。你忏悔么？Feardorchae:你的精神力量不够强，Oliver。你被这里的气息影响了。这会让你只想着杀戮。\nOliver:（感到魔力的涌动越发强烈）你......\nFeardorchae:（喘着气）被这里气息影响，消耗的魔力会成倍增加，好似燃烧自己的灵魂......\nFeardorchae:（喘着气）以你的消耗......如果你还要与我战斗，虽然你不至于彻底死去，也至少会变得虚弱。\nOliver:那这又怎么会成为我停止的理由呢。\n"};
//第一位地点：0若里村，1极寒之地，2火焰谷，3放逐之地。
//00,01铁匠，0203女巫，04商人，05老渔夫，0607奶奶，08疯子，09孩子
//10拒绝进入极寒之地的话，11拒绝进入城堡的对话
//20城堡上展示的文字，21解谜成功的话，22解谜失败的话。密码是13260119，游戏开始是1626年
//303132Oliver与一个手下的对话。33343536与satan等人的对话以及战斗。37追随者献祭自己。38394041与Feardorchae的对话
QString dialogue::end_str[10]={"",
                                 "Ending1：你给予了Feardorchae最后一击。Feardorchae却以一种异样的方式看向你，祂的遗言是，我的遗物都放在这个戒指里......祂的灵魂彻底的消散了。但Feardorchae的回忆碎片却涌向了你的脑海。“这里太亮太热了，我不喜欢这里.........你不喜欢黑夜么.......”不知怎么，Feardorchae的消失让你感到空虚......你想了想，还是拿走了Feardorchae的戒指。\n",
                                 "......你回到了若里村，告诉了人们躲避在放逐之地的魔王已经消逝的消息。人们对你的行为表达了由衷的感谢，并为你送上祝福。\n你和你作为青年Oliver的朋友们一一告别。你终究不能永远待在这个世界。\n......但你一直没有看Feardorchae的遗物。你决定到一个安静的地方去看。\n现在要做的，就是离开这里。\n在一片光芒中，你离开了这个世界。",
                                 "Ending2：你再一次攻击了Feardorchae。Feardorchae惊恐地看向你，“你疯了吗！你不知道这样你也会......”祂用所有魔力释放了用于抵挡的魔法。在剧烈的波动中，Feardorchae的灵魂彻底的消散了......\n你变得极度虚弱，你感受到似乎组成你的什么东西正在逐渐消失。过去的画面在你的脑海中闪过。一个个世界，似乎那么熟悉又遥远。最后，你想起了你最初如何从神域中诞生。那是一片无法用语言描述的魔力的海洋。你被包裹在中间，感到温暖，整个神域都如此平静。\n想到这些，你感到无尽的悲伤。你想哭，但神是没有眼泪的。你似乎感受到许多人在呼唤你的名字。这是我的结局么。你想。\n你艰难地张开嘴唇，告诉他们，再见......",
                                 "\n\n但是光明与黑暗总是事物的两面。\n\n在遥远的，广阔的神域中，经历漫长的时间\n\n新的Oliver与Feardorchae会诞生，他们会开启新的故事..........",
                                 "Ending3：你攻击了Feardorchae。尽管祂已经十分虚弱，但祂仍尽力抵挡了你的攻击。祂逃向魔法阵，用最后的魔力将灵体包裹，离开了这里。\n你试图追赶Feardorchae，但Feardorchae仿佛融入了无边的黑暗。你感到十分的疲惫，你用最后的魔力封存了你的记忆与力量。你实在撑不住了，你对世界的感知越来越弱，越来越弱......",
                                 "",
                                 "",
                                 "",
                                 ""};
//0102Ending1:Feardorchae死了，你拿到了祂的遗物。0304Ending2:Feardorchae与你都死了。05Ending3:Feardorchae逃走了，你封存记忆，开始新的轮回。
QString dialogue::other_str[10]={"据一本神秘的书籍记载，很久以前，Oliver是人们所信仰的神明，Feardorchae是无恶不作的Feardorchae。\n偶然的机会，Feardorchae来到了这个世界，给这片大陆上的人们带来了恐惧与痛苦。\nOliver为了保护人们，与R以及B的手下不断产生冲突。\n在最终的决战中，Oliver打败了Feardorchae，\n但Oliver十分虚弱，并且祂的追随者仍在与Feardorchae的手下战斗。\n因此Oliver将自己的记忆与力量都封存了起来，但做完这些之后Oliver已经失去了意识。\n现在，Oliver的灵魂转世成为一个18岁的青年，他仍然叫Oliver，生活在若里村。\nOliver少年时父母双亡，被当地的教会收养。Oliver幼年时性格随意，但生性善良。\n当地教会信仰Oliver，尽管当年的大战中人们都传说Oliver与Feardorchae都彻底地毁灭了，\n但教会仍然虔诚地信仰着Oliver。\nOliver常常对未来感到迷茫，他每天最喜欢在海边发呆，生活似乎就这么平静的进行下去\n......在这个游戏中，Oliver的许多行为都会对结局产生影响。祝你好运，Oliver。"
                                   ,"劳斯镇的人们都有早起早睡的习惯。\n谷比恩以产出黄金著称。\n灵魂圣地是传说中转世灵魂聚集的地方，有一位法师说灵魂会无意识地聚集在这里。\n这里没有村庄，没有人烟，只有河流，森林与小动物。而这些小动物似乎都带有某种灵性......\n极寒之地常年严寒，体格瘦弱的人无法忍受刺骨的寒风。\n传说这里有许多擅长灵魂类魔法的高手留下的灵魂秘籍。\n火焰谷出产最好的兵器,但如今已经少有人踏足此地。\n放逐之地是常人不愿接近的地方。那里常常是无边无际的黑暗，并且似乎连空气中都蕴含着无穷的魔力......\n近许多年去那里的人都没有回来过。而放逐之地对岸的城邦时刻提防着放逐之地的入侵。\n据说大海中有许多神奇的岛屿，它们有时在海面上方，有时却消失不见。\n已经许多年没有人看见这些岛了，这些岛屿的位置早已无人知晓。"
                                   ,"现在是1626年1月19日。\n每个事物都有其两面。但没有纯粹的善，也没有纯粹的恶。\n据说灵魂的消散才是彻底的消失。\n传说中存在一些令人延长生命的魔法，但只有极少数有天赋的人能够掌握，每次施展这种魔法需要耗费极大的精力与魔力，没有坚定意志支撑的灵魂甚至会直接消散......\n而即便成功，更长的生命往往带来更久的空虚。\n总有疯子说其他世界是存在的。但从来没人见过自称从其他世界来的人。\n嗨嗨嗨！来啦！给我有用的材料，我来帮你打造趁手的兵器！......\n你的武器已经被强化了！......\n找个怪物试试手吧！.....\n纯粹之刃！斩尽邪祟！......\n打铁还需自身硬！想跟我一起打会铁吗？\nOliver,如果你还活着,我会一直等着你......"
                                   ,"如果你读到这段文字，那么Feardorchae已经不复存在了。如果你不是Oliver,请把它交给Oliver,或者至少把这段故事告诉Oliver......虽然我想除了Oliver也没有神能击败我......\n我不记得很多幼年的事情了......只记得我最初诞生的地方,那是一片魔力的海洋......\n我小时候常常和..........(缺失了许多文字,似乎被烧掉了)\n我一诞生就喜欢黑暗,所以我总是呆在那些有深渊的世界里......\n本来在这些地方也没什么好的,许多人类看到我的化形都厌恶我，恐惧我，攻击我......\n我记得开始时我总是用魔法帮助深渊中的生物，但是它们仍然恐惧我...直到有一次我到了我现在居住的世界，用魔法摧毁了几个人类......\n结果那里的有些人类就跟着我，我走到哪里都甩不开他们......但是在我的眼中，他们的灵魂也没什么值得注意的......\n我不明白，我摧毁他们同类的灵魂，他们却狂热地追逐着我，仅仅是因为我的魔法过于强大么......(缺失了好多文字，被烧掉了)\n我不是生来就喜好杀戮......(缺失了好多文字)\n那种感觉令我迷醉，我开始控制不住自己......\n直到有一次我与那个神明大战，好不容易才逃脱出来。这段文字在我逃走休息时写下......\n我丢失了许多记忆。这些是我记得的全部内容了。Oliver,真的要这么对我么...(文字到这里就中断了)"};
//00游戏开始的文字，0102设定与提示。01关于地点。02一些话语,03Feardorcahe回忆录的残片。

