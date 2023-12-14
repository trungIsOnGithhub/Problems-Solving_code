class CreateParkSection < ActiveRecord::Migration[7.1]
  def change
    create_table :park_sections do |t|
      t.string :slot_type

      t.string :slot_name
      t.string :slot_num

      t.string :slot_status

      t.timestamps
    end
  end
end
